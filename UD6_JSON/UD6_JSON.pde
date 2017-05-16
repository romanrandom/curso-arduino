/**
 * Unidad 6: JSON
 *
 */

void setup() {
  JSONObject respuesta = loadJSONObject("http://api.openweathermap.org/data/2.5/weather?q=bilbao&units=metric&appid=7844f3eec4bfc5c936a0abd504804bfe");
  JSONObject main = respuesta.getJSONObject("main");  

  int temperatura = main.getInt("temp");
  println(temperatura);
}