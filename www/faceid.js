var exec = require('cordova/exec');

module.exports = {
    ID_CARD: {
        FRONT:  0,
        REAR: 1
    },

    auth: function (onSuccess, onError) {
        exec(onSuccess, onError, "FaceID", "auth", []);
    },

    takePicture: function (isFront, onSuccess, onError) {
        exec(onSuccess, onError, "FaceID", "takePicture", [isFront == FaceID.ID_CARD.FRONT]);
    }
};
