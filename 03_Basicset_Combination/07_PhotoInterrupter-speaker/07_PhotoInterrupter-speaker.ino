const int ruptPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB 10:Builtin

#define DO 261
#define _DO 277
#define RE 293
#define _RE 311
#define MI 329
#define FA 349
#define _FA 367
#define SO 392
#define _SO 415
#define RA 440
#define _RA 466
#define TI 494
#define octDO 523

bool play = false;
unsigned long stepTime = 0;
int step = 0;

struct MusicStep { // 音楽データ構造体
  int frequency;   // 周波数（0は無音）
  int duration;    // 持続時間（ms）
};


MusicStep musicData[] = { // 完全な音楽データをデータ化
  {RE, 180}, {0, 20},     // RE音符 + 休符
  {DO, 180}, {0, 20},     // DO音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {RE, 180}, {0, 20},     // RE音符 + 休符
  {DO, 180}, {0, 20},     // DO音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {RE, 180}, {0, 20},     // RE音符 + 休符
  {DO, 180}, {0, 20},     // DO音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {RE, 300}, {0, 100},    // RE音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {DO, 300}, {0, 100},    // DO音符 + 休符
  {MI, 300}, {0, 100},    // MI音符 + 休符
  {MI, 300}, {0, 100},    // MI音符 + 休符
  {RE, 200},              // RE音符（休符なし）
  {DO, 200},              // DO音符（休符なし）
  {DO, 300}, {0, 100},    // DO音符 + 休符
  {MI, 300}, {0, 100},    // MI音符 + 休符
  {MI, 300}, {0, 100},    // MI音符 + 休符
  {RE, 180}, {0, 20},     // RE音符 + 休符
  {DO, 180}, {0, 20},     // DO音符 + 休符
  {DO, 300}, {0, 100},    // DO音符 + 休符
  {MI, 300}, {0, 100},    // MI音符 + 休符
  {MI, 300}, {0, 100},    // MI音符 + 休符
  {RE, 180}, {0, 20},     // RE音符 + 休符
  {DO, 180}, {0, 20},     // DO音符 + 休符
  {DO, 300}, {0, 100},    // DO音符 + 休符
  {MI, 300}, {0, 100},    // MI音符 + 休符
  {RE, 300}, {0, 100},    // RE音符 + 休符
  {MI, 300}, {0, 100},    // MI音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {FA, 300}, {0, 100},    // FA音符 + 休符
  {0, 250}                // 最終休符
};

int musicDataLength = sizeof(musicData) / sizeof(musicData[0]);


void setup() {
  Serial.begin(115200);
  pinMode(ruptPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}

void loop() {
  if (digitalRead(ruptPin) == LOW && !play) {
    Serial.println("Animal Intrusion!");
    startMusic();
  } else if (digitalRead(ruptPin) == HIGH && play){
    Serial.println("Animal Escape!"); 
    stopMusic();
  }

  if (play){
    updateMusic();
  } else {
    Serial.println("none");
    delay(1000);
  }
}

void startMusic() {
  play = true;
  stepTime = millis();
  step = 0;  // 常に最初から開始
  
  ledcWriteTone(spkrPin, musicData[0].frequency); // 最初のステップを開始
}

void stopMusic() {
  play = false;
  ledcWriteTone(spkrPin, 0); // 音を停止
  // currentStepはリセットしない（次回startMusic()でリセット）
}

void updateMusic() {
  unsigned long currentTime = millis();
  
  // 現在のステップの再生時間をチェック
  if (currentTime - stepTime >= musicData[step].duration) { // 次のステップへ進む

    step++;
    stepTime = currentTime;
    
    if (step < musicDataLength) {
      // 次のステップを再生
      ledcWriteTone(spkrPin, musicData[step].frequency);
    } else {
      // 音楽終了
      stopMusic();
    }
  }
}
