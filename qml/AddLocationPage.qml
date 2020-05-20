import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.12

import Felgo 3.0

Page {
    id: page
    property alias messageText: messageText.text

    Component.onCompleted: {
        weatherReceiver.setWeatherData(weatherData)

        const recentLocations = weatherReceiver.recentLocations()

        recentLocations.forEach(function(item){
            listModel.append({ name: item })
        });
    }

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

        //Image {source:"../assets/img/clouds.png"; anchors.fill: parent}

        Column
        {
            id: column
            spacing: 10
            anchors.centerIn: parent
            height: parent.height / 2

            AppText {
                id: messageText
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                fontSize: 14
            }

            AppText {
                id: appText
                width: parent.width
                text: qsTr("Add City")
                horizontalAlignment: Text.AlignHCenter
                fontSize: 28
            }

            AppTextField {
                id: cityEdit
                color: "black"
                width: page.width / 1.3
                text: "Ivano-Frankivsk"
            }

            AppButton {
                id: appButton
                text:  qsTr("Add")
                antialiasing: true
                anchors.right: parent.right
                icon: qsTr("")
                rippleEffect: true

                onClicked: weatherMainPage.getData(cityEdit.text)
            }

            AppListView {
                id: appListView

                model: ListModel { id: listModel }

                delegate: SimpleRow {
                    AppTextField {
                        background:   Rectangle {
                            width: parent.width
                            height: parent.height

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
                        }

                        width: appListView.width
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: name
                        color: "black"
                        readOnly: true

                        Rectangle {
                            id: rect
                            anchors.fill: parent
                            color: "transparent"

                            MouseArea {
                                anchors.fill: parent
                                propagateComposedEvents: true
                                cursorShape: Qt.PointingHandCursor

                                onClicked: weatherMainPage.getData(name)
                                onPressedButtonsChanged: {  pressed ? rect.color = "#1AD6FD" : rect.color = "transparent" }
                            }
                        }
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
