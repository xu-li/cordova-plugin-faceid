var exec = require('cordova/exec');

var FaceID = {

    ID_CARD: {
        FRONT: 0,
        REAR: 1
    },

    ERROR_AUTH:    '授权失败',
    ERROR_CANCEL:  '用户取消了操作',
    ERROR_UNKNOWN: '未知错误',

    auth: function (onSuccess, onError) {
        exec(onSuccess, onError, "FaceID", "auth", []);
    },

    takeIDCardPicture: function (isFront, onSuccess, onError) {
        this.auth(function (success) {
            if (success) {
                exec(function (result) {
                    if (!result.hasOwnProperty('idcard') || !result.idcard) {
                        onError && onError(FaceID.ERROR_CANCEL);
                        return ;
                    }

                    var portrait = result.hasOwnProperty('portrait') && result.portrait ? result.portrait : '';
                    onSuccess && onSuccess(result.idcard, portrait);
                }, function () {
                    onError && onError(FaceID.ERROR_UNKNOWN);
                }, "FaceID", "takeIDCardPicture", [isFront == FaceID.ID_CARD.FRONT]);
            } else {
                onError && onError(FaceID.ERROR_AUTH);
            }
        }, function () {
            onError && onError(FaceID.ERROR_UNKNOWN);
        });
    },

    takeHeadshotPicture: function (onSuccess, onError) {
        this.auth(function (success) {
            if (success) {
                exec(function (result) {
                    if (!result.hasOwnProperty('headshot') || !result.headshot) {
                        onError && onError(FaceID.ERROR_CANCEL);
                        return ;
                    }
                    onSuccess && onSuccess(result.headshot);
                }, function () {
                    onError && onError(FaceID.ERROR_UNKNOWN);
                }, "FaceID", "takeHeadshotPicture");
            } else {
                onError && onError(FaceID.ERROR_AUTH);
            }
        }, function () {
            onError && onError(FaceID.ERROR_UNKNOWN);
        });
    }
};

module.exports = FaceID;
