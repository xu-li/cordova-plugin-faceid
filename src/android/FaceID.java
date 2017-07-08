package xu.li.cordova.faceid;

import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.util.Base64;

import com.megvii.idcardlib.IDCardScanActivity;
import com.megvii.idcardquality.IDCardQualityLicenseManager;
import com.megvii.licensemanager.Manager;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaArgs;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.UnsupportedEncodingException;

import static android.app.Activity.RESULT_OK;

public class FaceID extends CordovaPlugin
{
    public static final String TAG = "Cordova.Plugin.FaceID";
    public static final String UUID = "";

    public static final int REQ_CODE_PERM_CAMERA  = 0;
    public static final int REQ_CODE_TAKE_PICTURE = 1;

    public static final String ERROR_PERMISSION_DENIED = "权限错误";

    protected CallbackContext callbackContext;
    protected CordovaArgs args;

    @Override
    public boolean execute(String action, CordovaArgs args, CallbackContext callbackContext) throws JSONException {
        Log.d(TAG, String.format("%s is called. Callback ID: %s.", action, callbackContext.getCallbackId()));

        this.args = args;
        this.callbackContext = callbackContext;

        if (action.equals("auth")) {
            return auth();
        } else if (action.equals("takePicture")) {
            return takePicture();
        }

        return false;
    }

    protected boolean auth()
            throws JSONException {

        final Activity activity = cordova.getActivity();

        // run in background
        cordova.getThreadPool().execute(new Runnable() {

            @Override
            public void run() {
                Manager manager = new Manager(activity);
                IDCardQualityLicenseManager idCardLicenseManager = new IDCardQualityLicenseManager(
                        activity);
                manager.registerLicenseManager(idCardLicenseManager);
                manager.takeLicenseFromNetwork(UUID);

                if (idCardLicenseManager.checkCachedLicense() > 0) {
                    callbackContext.success(1);
                } else {
                    callbackContext.success(0);
                }
            }
        });

        return true;
    }

    protected boolean takePicture() {
        if (!cordova.hasPermission(Manifest.permission.CAMERA)) {
            cordova.requestPermission(this, REQ_CODE_PERM_CAMERA, Manifest.permission.CAMERA);
        } else {
            sendTakePictureIntent();
        }

        return true;
    }

    public void onRequestPermissionResult(int requestCode, String[] permissions,
                                          int[] grantResults) throws JSONException
    {
        for (int r : grantResults) {
            if (r == PackageManager.PERMISSION_DENIED) {
                this.callbackContext.sendPluginResult(new PluginResult(PluginResult.Status.ERROR, ERROR_PERMISSION_DENIED));
                return;
            }
        }

        if (requestCode != REQ_CODE_TAKE_PICTURE) {
            return ;
        }

        sendTakePictureIntent();
    }

    protected void sendTakePictureIntent()
    {
        if (callbackContext == null || args == null) {
            return ;
        }

        boolean frontSide = args.isNull(0) ? true : args.optBoolean(0);

        Intent intent = new Intent(cordova.getActivity(), IDCardScanActivity.class);
        intent.putExtra("side", frontSide ? 0 : 1);
        intent.putExtra("isvertical", false);

        cordova.startActivityForResult(this, intent, REQ_CODE_TAKE_PICTURE);
    }

    /**
     * Called when a plugin is the recipient of an Activity result after the
     * CordovaActivity has been destroyed. The Bundle will be the same as the one
     * the plugin returned in onSaveInstanceState()
     *
     * @param state             Bundle containing the state of the plugin
     * @param callbackContext   Replacement Context to return the plugin result to
     */
    public void onRestoreStateForActivityResult(Bundle state, CallbackContext callbackContext)
    {
        this.callbackContext = callbackContext;
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent intent)
    {
        super.onActivityResult(requestCode, resultCode, intent);

        if (requestCode != REQ_CODE_TAKE_PICTURE || resultCode != RESULT_OK) {
            return ;
        }

        JSONObject result = new JSONObject();
        try {
            int frontSide = intent.getIntExtra("side", 0);
            result.put("is_front_side", frontSide == 0 ? true : false);

            try {
                byte[] idCard = intent.getByteArrayExtra("idcardImg");
                result.put("idcard_image", "data:image/bmp;base64," + new String(Base64.encode(idCard, Base64.NO_WRAP), "US-ASCII"));
            } catch (UnsupportedEncodingException ex1) {
                callbackContext.sendPluginResult(new PluginResult(PluginResult.Status.ERROR));
            }

            if (frontSide == 0) {
                try {
                    byte[] portrait = intent.getByteArrayExtra("portraitImg");

                    if (portrait.length > 0) {
                        result.put("portrait_image", "data:image/bmp;base64," + new String(Base64.encode(portrait, Base64.NO_WRAP), "US-ASCII"));
                    }
                } catch (UnsupportedEncodingException ex2) {
                    // do nothing
                }
            }

            callbackContext.sendPluginResult(new PluginResult(PluginResult.Status.OK, result));
        } catch (JSONException jsonEx) {
            callbackContext.sendPluginResult(new PluginResult(PluginResult.Status.ERROR));
        }
    }
}
