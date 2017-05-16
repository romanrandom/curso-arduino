/** 
 *  Unidad 5: MIDI
 *  Notas MIDI:
 *  http://www.electronics.dit.ie/staff/tscarff/Music_technology/midi/midi_note_numbers_for_octaves.htm
 */

#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

byte nota;

void setup() {
    
  MIDI.begin();         // Podemos seleccionar el canal o usar 1 por defecto
  Serial.begin(115200); //Cambiamos la velocidad del puerto serie

}

void loop() {
  
  nota = random(60, 96);
  
  MIDI.sendNoteOn(nota, 127, 1);    // Send a Note (pitch 42, velo 127 on channel 1)
  delay(333);                // Wait for a second
  MIDI.sendNoteOff(nota, 0, 1);     // Stop the note
  delay(333);
  MIDI.sendNoteOn(nota - 12, 100, 1);    // Send a Note (pitch 42, velo 127 on channel 1)
  delay(333);
  MIDI.sendNoteOff(nota - 12, 0, 1);     // Stop the note
}
