import QtQuick 2.9
import QtQuick.Window 2.2
import MyApp.Images 1.0

Window {
    id: mainWindow
    visible: true
    title: "test"

    Component.onCompleted: mainWindow.showFullScreen()

    LiveImage {
        width: 480
        height: 480
        x: 0
        y: 0
        image: LiveImageProvider.image
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:480}
}
##^##*/
