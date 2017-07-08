package com.megvii.idcardlib.view;

import com.megvii.idcardlib.R;
import com.megvii.idcardquality.bean.IDCardAttr;
import android.app.Activity;
import android.content.Context;
import android.graphics.*;
import android.util.AttributeSet;
import android.view.View;

/**
 * Created by binghezhouke on 15-8-12.
 */
public class IDCardNewIndicator extends View {
	private Rect mShowDrawRect = null;
	private Rect mDrawRect = null;
	private Paint mDrawPaint = null;
	private Paint mDrawRightPaint = null;
	private float IDCARD_RATIO = 856.0f / 540.0f;
	private float CONTENT_RATIO = 0.8f;
	private float SHOW_CONTENT_RATIO = CONTENT_RATIO * 13.0f / 16.0f;

	private float RIGHT_RATIO = 0.2f;
	private RectF rightRectf = null;
	private Rect mTmpRect = null;
	private Rect mTmpRect_test = null;
	private Bitmap rightBitmap;
	private String rightText;
	private int right_width = 0;
	private int right_height = 0;
	private int backColor = 0x00000000;

	private void init() {
		rightRectf = new RectF();
		mShowDrawRect = new Rect();
		mDrawRect = new Rect();
		mTmpRect = new Rect();
		mTmpRect_test = new Rect();
		mDrawRightPaint = new Paint();
		mDrawRightPaint.setColor(0XFFFFFFFF);
		mDrawPaint = new Paint();
		mDrawPaint.setDither(true);
		mDrawPaint.setAntiAlias(true);
		mDrawPaint.setStrokeWidth(10);
		mDrawPaint.setStyle(Paint.Style.STROKE);
		mDrawPaint.setColor(0xff0000ff);
	}

	public void setBackColor(Activity activity, int backColor) {
		if (this.backColor != backColor) {
			this.backColor = backColor;
			activity.runOnUiThread(new Runnable() {
				@Override
				public void run() {
					IDCardNewIndicator.this.invalidate();
				}
			});
		}
	}

	public void setRightImage(boolean isFront) {
		if (isFront) {
			rightText = "请将身份证正";
			rightBitmap = BitmapFactory.decodeResource(getResources(), R.drawable.sfz_front);
		} else {
			rightText = "请将身份证背";
			rightBitmap = BitmapFactory.decodeResource(getResources(), R.drawable.sfz_back);
		}
	}

	public IDCardNewIndicator(Context context) {
		super(context);
		init();
	}

	public IDCardNewIndicator(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}

	public IDCardNewIndicator(Context context, AttributeSet attrs, int defStyleAttr) {
		super(context, attrs, defStyleAttr);
		init();
	}

	// 只考虑横屏
	@Override
	protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
		super.onMeasure(widthMeasureSpec, heightMeasureSpec);
		int width = MeasureSpec.getSize(widthMeasureSpec);
		int height = MeasureSpec.getSize(heightMeasureSpec);

		right_width = (int) (width * RIGHT_RATIO);
		right_height = (int) (right_width / IDCARD_RATIO);

		// 实际身份证位置的中心点
		int centerY = height >> 1;
		int centerX = width >> 1;

		int content_width = (int) ((width - right_width) * CONTENT_RATIO);
		int content_height = (int) (content_width / IDCARD_RATIO);

		mDrawRect.left = centerX - content_width / 2;
		mDrawRect.top = centerY - content_height / 2;
		mDrawRect.right = content_width + mDrawRect.left;
		mDrawRect.bottom = content_height + mDrawRect.top;

		int content_show_width = (int) ((width - right_width) * SHOW_CONTENT_RATIO);
		int content_show_height = (int) (content_show_width / IDCARD_RATIO);

		mShowDrawRect.left = (int)(centerX - content_show_width / 2.0f);
		mShowDrawRect.top = centerY - content_show_height / 2;
		mShowDrawRect.right = content_show_width + mShowDrawRect.left;
		mShowDrawRect.bottom = content_show_height + mShowDrawRect.top;

		rightRectf.top = mShowDrawRect.top;
		rightRectf.left = mDrawRect.right;
		rightRectf.right = width - 20;
		rightRectf.bottom = rightRectf.width() / IDCARD_RATIO + rightRectf.top;
	}

	@Override
	protected void onDraw(Canvas canvas) {
		// background
		mDrawPaint.setStyle(Paint.Style.FILL);
		mDrawPaint.setColor(backColor);

		drawViewfinder(canvas);
		//onDrawRight(canvas);
	}

	private boolean mIsVertical;
	private IDCardAttr.IDCardSide mIdCardSide;

	public void setCardSideAndOrientation(boolean mIsVertical, IDCardAttr.IDCardSide mIDCardSide) {
		this.mIsVertical = mIsVertical;
		this.mIdCardSide = mIDCardSide;
	}

	private void drawViewfinder(Canvas canvas) {
		// top
		mTmpRect.set(0, 0, getWidth(), mShowDrawRect.top);
		canvas.drawRect(mTmpRect, mDrawPaint);
		// bottom
		mTmpRect.set(0, mShowDrawRect.bottom, getWidth(), getHeight());
		canvas.drawRect(mTmpRect, mDrawPaint);
		// left
		mTmpRect.set(0, mShowDrawRect.top, mShowDrawRect.left, mShowDrawRect.bottom);
		canvas.drawRect(mTmpRect, mDrawPaint);
		// right
		mTmpRect.set(mShowDrawRect.right, mShowDrawRect.top, getWidth(), mShowDrawRect.bottom);
		canvas.drawRect(mTmpRect, mDrawPaint);

		// rect
		mDrawPaint.setStyle(Paint.Style.STROKE);
		mDrawPaint.setColor(0xff5fc0d2);
		mDrawPaint.setStrokeWidth(5);
		int length = mShowDrawRect.height() / 16;
		// left top
		canvas.drawLine(mShowDrawRect.left, mShowDrawRect.top, mShowDrawRect.left + length, mShowDrawRect.top,
				mDrawPaint);
		canvas.drawLine(mShowDrawRect.left, mShowDrawRect.top, mShowDrawRect.left, mShowDrawRect.top + length,
				mDrawPaint);

		// right top
		canvas.drawLine(mShowDrawRect.right, mShowDrawRect.top, mShowDrawRect.right - length, mShowDrawRect.top,
				mDrawPaint);
		canvas.drawLine(mShowDrawRect.right, mShowDrawRect.top, mShowDrawRect.right, mShowDrawRect.top + length,
				mDrawPaint);

		// left bottom
		canvas.drawLine(mShowDrawRect.left, mShowDrawRect.bottom, mShowDrawRect.left + length, mShowDrawRect.bottom,
				mDrawPaint);
		canvas.drawLine(mShowDrawRect.left, mShowDrawRect.bottom, mShowDrawRect.left, mShowDrawRect.bottom - length,
				mDrawPaint);

		// right bottom
		canvas.drawLine(mShowDrawRect.right, mShowDrawRect.bottom, mShowDrawRect.right - length, mShowDrawRect.bottom,
				mDrawPaint);
		canvas.drawLine(mShowDrawRect.right, mShowDrawRect.bottom, mShowDrawRect.right, mShowDrawRect.bottom - length,
				mDrawPaint);

		int bitmapId = 0;
		if (mIdCardSide == IDCardAttr.IDCardSide.IDCARD_SIDE_FRONT)
			bitmapId = R.drawable.sfz_front;
		else if (mIdCardSide == IDCardAttr.IDCardSide.IDCARD_SIDE_BACK)
			bitmapId = R.drawable.sfz_back;
		Bitmap bitmap = BitmapFactory.decodeResource(getContext().getResources(), bitmapId);
		Rect mSrcRect = new Rect(0, 0, bitmap.getWidth(), bitmap.getHeight());
		Rect mDesRect = new Rect(mShowDrawRect.left, mShowDrawRect.top, mShowDrawRect.left + mShowDrawRect.width(), mShowDrawRect.top + mShowDrawRect.height());
		canvas.drawBitmap(bitmap, mSrcRect, mDesRect, null);
	}
	
	private void onDrawRight(Canvas canvas) {
		canvas.drawBitmap(rightBitmap, null, rightRectf, null);
		int textSize = right_width / 6;
		mDrawRightPaint.setTextSize(textSize * 4 / 5);
		canvas.drawText(rightText + "面", rightRectf.left, rightRectf.bottom + textSize, mDrawRightPaint);
		canvas.drawText("置于框内", rightRectf.left, rightRectf.bottom + textSize * 2, mDrawRightPaint);
	}

	public RectF getPosition() {
		RectF rectF = new RectF();
		rectF.left = mDrawRect.left / (float) getWidth();
		rectF.top = mDrawRect.top / (float) getHeight();
		rectF.right = mDrawRect.right / (float) getWidth();
		rectF.bottom = mDrawRect.bottom / (float) getHeight();
		return rectF;
	}
	public Rect getMargin() {
		Rect rect = new Rect();
		rect.left = mDrawRect.left;
		rect.top = mDrawRect.top;
		rect.right = getWidth() - mDrawRect.right;
		rect.bottom = getHeight() - mDrawRect.bottom;
		return rect;
	}
}
