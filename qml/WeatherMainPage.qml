import QtQuick 2.4
import QtQuick.Controls 1.2

import Felgo 3.0

Page {
    id: page
    visible: weatherData.visible
    property var today: alldata[currentIndex]
    property int currentIndex: 0
    property string error: weatherData.error

    onErrorChanged: {
        addLocationPage.errorText = error
        addLocationPage.visible = !weatherData.visible
        page.visible = weatherData.visible
    }

    function getData(location) {
        weatherData.location = location
        weatherReceiver.getWeather()
    }

    property var alldata: [
        { temperature: weatherData.currentTemperature, description: weatherData.description },
        { temperature: weatherData.currentTemperature, description:  weatherData.description }
    ]

    Rectangle {
        x: -page.safeArea.x
        y: -page.safeArea.y
        width: page.width
        height: page.height

        gradient: Gradient {
            GradientStop {
                position: 0
                color: today.temperature < 20 ? "#1AD6FD" : "#FF5E3A"

                Behavior on color { ColorAnimation { duration: 1500 } }
            }
            GradientStop {
                position: 1
                color: today.temperature < 20 ? "#1D62F0" : "#FF2A68"

                Behavior on color { ColorAnimation { duration: 1000 } }
            }
        }
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        y: dp(10)
        spacing: dp(10)

        AppText {
            id: timeLabel

            font.pixelSize: sp(14)
            anchors.horizontalCenter: parent.horizontalCenter

            Timer {
                running: true
                interval: 1000 * 30
                triggeredOnStart: true
                repeat: true
                onTriggered: timeLabel.text = new Date().toLocaleTimeString(Qt.locale(), Locale.ShortFormat)
            }
        }

        AppText {
            id: cityText
            text: weatherData.location
            font.pixelSize: sp(22)
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle {
                id: rect
                anchors.fill: parent
                color: "transparent"

                MouseArea {
                    anchors.fill: parent
                    propagateComposedEvents: true
                    cursorShape: Qt.PointingHandCursor

                    onClicked: { page.visible = false; addLocationPage.visible = true }
                    onPressedButtonsChanged: {  pressed ? rect.color = "#1AD6FD" : rect.color = "transparent" }
                }
            }
        }
    }

    Column {
        id: col
        anchors.centerIn: parent

         AppText {
             text: qsTr("Humidity") + " " + weatherData.humidity + "%"
             anchors.horizontalCenter: parent.horizontalCenter
         }

        AppText {
            id: tempText

            property int temperature: today.temperature

            Component.onCompleted: text = temperature + "°"

            font.pixelSize: sp(140)
            anchors.horizontalCenter: parent.horizontalCenter

            onTemperatureChanged: {
                var currentTemp = parseInt(tempText.text)
                textTimer.restart()
            }

            Timer {
                id: textTimer
                interval: 40

                onTriggered: {
                    var currentTemp = parseInt(tempText.text)

                    if (tempText.temperature > currentTemp) {
                        tempText.text = ++currentTemp + "°"
                        restart()
                    }
                    else if (tempText.temperature < currentTemp) {
                        tempText.text = --currentTemp + "°"
                        restart()
                    }
                }
            }
        }

        AppText {
            id: descText
            text: today.description
            font.pixelSize: sp(28)
            anchors.horizontalCenter: parent.horizontalCenter

            Behavior on text {
                SequentialAnimation {
                    NumberAnimation { target: descText; property: "opacity"; to: 0 }
                    PropertyAction { }
                    NumberAnimation { target: descText; property: "opacity"; to: 1 }
                }
            }
        }
    }

    Grid {
        id: bottomGrid

        width: Math.min(parent.width - dp(20), dp(450))
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height - height - dp(10)
        columns: 5
        property var date: new Date()
        property var tomorrowDate: new Date(date.getFullYear(), date.getMonth(), date.getDate() + 1)

        Repeater {
            model: [
                { day: weatherData.forecastDay1, high: parseInt(weatherData.forecastMaxTemperature1), low: parseInt(weatherData.forecastMinTemperature1), icon: weatherData.forecastDescription1 },
                { day: weatherData.forecastDay2, high: parseInt(weatherData.forecastMaxTemperature2), low: parseInt(weatherData.forecastMinTemperature2), icon: weatherData.forecastDescription2 },
                { day: weatherData.forecastDay3, high: parseInt(weatherData.forecastMaxTemperature3), low: parseInt(weatherData.forecastMinTemperature3), icon: weatherData.forecastDescription3 },
                { day: weatherData.forecastDay4, high: parseInt(weatherData.forecastMaxTemperature4), low: parseInt(weatherData.forecastMinTemperature4), icon: weatherData.forecastDescription4 },
                { day: weatherData.forecastDay5, high: parseInt(weatherData.forecastMaxTemperature5), low: parseInt(weatherData.forecastMinTemperature5), icon: weatherData.forecastDescription5 }
            ]

            Column {
                width: bottomGrid.width / 5
                spacing: dp(5)

                Icon {
                    icon: modelData.icon
                    anchors.horizontalCenter: parent.horizontalCenter
                    size: dp(20)
                }

                Item {
                    width: 1
                    height: dp(5)
                }

                AppText {
                    text: modelData.high
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: sp(14)
                }

                AppText {
                    text: modelData.low
                    color: "#aaffffff"
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: sp(14)
                }

                Item {
                    width: 1
                    height: dp(5)
                }

                AppText {
                    text: modelData.day
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: sp(14)
                }
            }
        }
    }
}
