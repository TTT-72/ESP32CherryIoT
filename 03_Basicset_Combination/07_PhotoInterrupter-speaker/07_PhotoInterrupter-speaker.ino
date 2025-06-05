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

bool play = false;          //再生判定フラグ。
unsigned long stepTime = 0; //
int step = 0;               //現在の楽譜再生位置。1和音のキー打に相当。

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

int musicDataLength = sizeof(musicData) / sizeof(musicData[0]); //音楽全体の処理数。全体のデータ量（バイト/全体）を1データ量（バイト/1要素）で割ると要素数が出る。


void setup() {
  Serial.begin(115200);
  pinMode(ruptPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}


void loop() {                                        // メイン処理。センサー認識時に再生
  if (digitalRead(ruptPin) == LOW && !play) {        // もしセンサーが認識、playがfalseなら
    Serial.println("Animal Intrusion!");
    startMusic();                                    // 再生始動用関数呼び出し
  } else if (digitalRead(ruptPin) == HIGH && play){  // もしセンサー待機状態＋playがfalseなら
    Serial.println("Animal Escape!"); 
    stopMusic();                                     //停止用関数呼び出し
  }

  if (play){                //playがtrueの際に分岐（変数：playはstartMusic関数内でtrueに切り替わっている）
    updateMusic();          //再生を続行する関数を呼び出し。
  } else {
    Serial.println("none"); //通常の待機状態
    delay(1000);
  }
}

void startMusic() {     //再生始動用関数:定義
  play = true;          //再生を続けるフラグをオン
  stepTime = millis();  //millis関数。マイコンの累積起動時間を返す。
  step = 0;             //再生を開始する音符の位置。停止時の再生再開位置を兼ねる。今回は最初からに固定
  
  ledcWriteTone(spkrPin, musicData[0].frequency); // 最初のステップを開始
}

void stopMusic() {           //停止用関数
  play = false;              //再生フラグをオフに。ここでupdateMusic関数の呼び出しフラグが折れる
  ledcWriteTone(spkrPin, 0); // 音を停止
}

void updateMusic() {                                        //実際の再生機構。音を鳴らすメイン機能
  unsigned long currentTime = millis();                     //現在時刻を取得
  
  if (currentTime - stepTime >= musicData[step].duration) { //現在時刻-startMusic関数で取得した時間 >= 現在再生中の音符(step)の長さ(duration:ミリ秒)
                                                            //→十分な演奏時間 >=　楽譜指定時間を超え次の音符へ　delayコマンドの代わりに音を出す時間を規定
    step++;                                                 //次の音符へ遷移
    stepTime = currentTime;                                 //startMusicを挟まないので、次の stepTime を規定して次音符へ
    
    if (step < musicDataLength) {  //現在の音符の演奏位置<音符の最大数
      ledcWriteTone(spkrPin, musicData[step].frequency); //現在のステップ位置を演奏
    } else {
      stopMusic(); //音符が終わったので演奏終了
    }
  }
}
