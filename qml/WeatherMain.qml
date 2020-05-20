import Felgo 3.0
import QtQuick 2.0

import com.OlegZiakun 1.0

App {
  id: app

  FontLoader { id: normalFont; source: "fonts/Lato-Light.ttf" }

  onInitTheme: {
    Theme.colors.textColor = "white"
    Theme.colors.statusBarStyle = Theme.colors.statusBarStyleHidden
    Theme.normalFont = normalFont
  }

  WeatherData { id: weatherData }
  AddLocationPage {id: addLocationPage}
  WeatherMainPage {id: weatherMainPage}
}
