import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.12

import Felgo 3.0

Page {
    id: page

    // Background
    Rectangle {
        x: -page.safeArea.x
        y: -page.safeArea.y
        width: page.width
        height: page.height

        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#1AD6FD"

                Behavior on color { ColorAnimation { duration: 1500 } }
            }
            GradientStop {
                position: 1
                color: "#1D62F0"

                Behavior on color { ColorAnimation { duration: 1000 } }
            }
        }

        Column
        {
            //anchors.fill: parent
            spacing: 10
            //   Layout.alignment: Qt.AlignHCenter
            anchors.centerIn: parent

            AppText {
                id: appText
                width: parent.width
                //anchors.centerIn: parent
                text: qsTr("Add Location")
                horizontalAlignment: Text.AlignHCenter
                fontSize: 28
            }

            //            Column
            //            {
            // anchors.fill: page

            // Layout.alignment: Qt.AlignHCenter

            //anchors.centerIn: page

            SearchBar {
                id: searchBar
                width: page.width / 1.3

                //anchors.centerIn: parent
            }

            AppButton {
                id: appButton
                text:  qsTr("Add")
            }
        }
    }
    //}
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
