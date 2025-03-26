#include <Arduino.h>

// Sözlükteki kelime verilerini tutan yapı.
struct WordData {
  String key;
  String meaning;
  String example;
};

// Sözlük dizisi.
const WordData sozluk[] = {
  {"CRINGE", "Garip ya da utandırıcı", "Bu video çok CRINGE!"},
  {"LOL", "Komik bir şey", "Adam düştü, LOL!"},
  {"ROFL", "Çok komik, gülmekten kırıldım", "Bu şaka ROFL!"},
  {"WTF", "Şaşkınlık verici", "Bu ne ya, WTF?!"},
  {"OMG", "Aman tanrım, ne oldu?", "OMG! Yeni haber!"},
  {"SMH", "Baş sallama", "Bu notlara bak, SMH!"},
  {"BRB", "Hemen döneceğim", "Biraz ara veriyorum, BRB!"},
  {"BTW", "Bu arada", "BTW, buldun mu?"},
  {"TBH", "Açıkçası", "TBH, o kadar da iyi değil."},
  {"FTW", "Harika!", "Gol FTW!"},
  {"TMI", "Fazla bilgi", "TMI, yeter artık!"},
  {"YOLO", "Hayat bir kez yaşanır", "YOLO, dene bakalım!"},
  {"FOMO", "Kaçırma korkusu", "FOMO yaşıyorum, gitmeliyim!"},
  {"BFF", "En iyi arkadaş", "O benim BFF'im."},
  {"IDC", "Umursamıyorum", "IDC, boşver!"},
  {"IKR", "Aynen", "Hava çok sıcak, IKR!"},
  {"NSFW", "Uygun olmayan içerik", "Bu video NSFW!"},
  {"JK", "Şaka yapıyorum", "Sınav iptal oldu, JK!"},
  {"DM", "Özel mesaj", "Adresini DM at."}
};
const int sozlukBoyutu = sizeof(sozluk) / sizeof(sozluk[0]);

// İki kelimenin aynı pozisyondaki harflerini karşılaştırıp benzerlik oranını hesaplar.
float basit_benzerlik(String k1, String k2) {
  k1.toUpperCase();
  k2.toUpperCase();
  int eslesen = 0;
  int len = min(k1.length(), k2.length());
  for (int i = 0; i < len; i++) {
    if (k1.charAt(i) == k2.charAt(i)) {
      eslesen++;
    }
  }
  int maxLen = max(k1.length(), k2.length());
  return (float)eslesen / maxLen;
}

// Girilen kelimeye en yakın kelimeyi, belirli eşik değeri üzerinde arar.
String en_yakin_kelime(String girdi, float esik = 0.6) {
  float en_iyi_oran = 0;
  String en_iyi = "";
  for (int i = 0; i < sozlukBoyutu; i++) {
    float oran = basit_benzerlik(girdi, sozluk[i].key);
    if (oran > en_iyi_oran) {
      en_iyi_oran = oran;
      en_iyi = sozluk[i].key;
    }
  }
  return (en_iyi_oran >= esik) ? en_iyi : "";
}

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); } // Seri port açılmasını bekler.
  Serial.println("Sozluk Uygulamasi Basladi!");
}

void loop() {
  Serial.println("Anlamadigin bir kelime yaz:");
  
  // Kullanıcı girişini bekler.
  while (Serial.available() == 0) {
    delay(10);
  }
  
  String girdi = Serial.readStringUntil('\n');
  girdi.trim();
  girdi.toUpperCase();
  
  if (girdi.length() == 0) return;
  
  bool bulundu = false;
  // Sözlükte tam eşleşme kontrolü.
  for (int i = 0; i < sozlukBoyutu; i++) {
    if (girdi == sozluk[i].key) {
      Serial.print("Anlam: ");
      Serial.println(sozluk[i].meaning);
      Serial.print("Ornek: ");
      Serial.println(sozluk[i].example);
      bulundu = true;
      break;
    }
  }
  
  // Eğer tam eşleşme bulunamadıysa, benzerlik oranına göre yakın kelimeyi öner.
  if (!bulundu) {
    String yakin = en_yakin_kelime(girdi);
    if (yakin != "") {
      for (int i = 0; i < sozlukBoyutu; i++) {
        if (yakin == sozluk[i].key) {
          Serial.print("Bunu mu demek istedin? ");
          Serial.println(sozluk[i].key);
          Serial.print("Anlam: ");
          Serial.println(sozluk[i].meaning);
          Serial.print("Ornek: ");
          Serial.println(sozluk[i].example);
          break;
        }
      }
    } else {
      Serial.println("Henüz bu kelime sozlukte yok, ama üzerinde calisiyoruz!");
    }
  }
  
  Serial.println(); // Bir sonraki giriş öncesi boş satır.
  delay(500);
}
