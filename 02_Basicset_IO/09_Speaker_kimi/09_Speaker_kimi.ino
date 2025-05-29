const int spkrPin = 3; //3:ConnectorA 4:ConnectorB

#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define TI 493.883
#define octDO 523.251

void playmusic(){
  ledcWriteTone(spkrPin, RA); delay(300);  // ラ
  ledcWriteTone(spkrPin, SI); delay(300);  // シ
  ledcWriteTone(spkrPin, DO); delay(300);  // ド
  ledcWriteTone(spkrPin, SI); delay(300);  // シ

  // 第2小節（右手）
  ledcWriteTone(spkrPin, DO); delay(300);  // ド
  ledcWriteTone(spkrPin, MI); delay(300);  // ミ
  ledcWriteTone(spkrPin, SI); delay(300);  // シ
  ledcWriteTone(spkrPin, MI); delay(300);  // ミ（左手伴奏代用）

  // 第3小節（右手／左手）
  ledcWriteTone(spkrPin, RA); delay(600);  // ラー（伸ばす）
  ledcWriteTone(spkrPin, SO); delay(300);  // ソ
  ledcWriteTone(spkrPin, RA); delay(600);  // ラー（伸ばす）
  ledcWriteTone(spkrPin, DO); delay(300);  // ド

  // 第4小節（左手伴奏）
  ledcWriteTone(spkrPin, SO); delay(600);  // ソー（伸ばす）
  ledcWriteTone(spkrPin, MI); delay(300);  // ミ
  ledcWriteTone(spkrPin, MI); delay(300);  // ミ
  ledcWriteTone(spkrPin, FA); delay(300);  // ファ

  // 第5小節（右手）
  ledcWriteTone(spkrPin, MI); delay(300);  // ミ
  ledcWriteTone(spkrPin, FA); delay(300);  // ファ
  ledcWriteTone(spkrPin, DO); delay(300);  // ド
  ledcWriteTone(spkrPin, MI); delay(300);  // ミ

  // 第6小節（右手／左手）
  ledcWriteTone(spkrPin, DO); delay(300);  // ド
  ledcWriteTone(spkrPin, DO); delay(300);  // ド
  ledcWriteTone(spkrPin, DO); delay(300);  // ド
  ledcWriteTone(spkrPin, SI); delay(300);  // シ

  // 第7小節（左手）
  ledcWriteTone(spkrPin, FA); delay(600);  // ファー（伸ばす）
  ledcWriteTone(spkrPin, SI); delay(300);  // シ
  ledcWriteTone(spkrPin, SI); delay(300);  // シ
  ledcWriteTone(spkrPin, 0); // no sound
  delay(250);
}

void setup() {
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}

void loop() {
  playmusic();
  delay(500);
}
