# ESP32 Sözlük Uygulaması

ESP32 mikrodenetleyicisi üzerinde çalışan bu proje, seri port üzerinden kullanıcıdan alınan kelimelerin anlamlarını ve örnek cümlelerini sağlayan bir sözlük uygulamasıdır. Kullanıcı, anlamını bilmediği bir kelimeyi girdiğinde, uygulama sözlükte arama yaparak ilgili bilgileri ekrana yansıtır.

## Özellikler

- **Kelime Anlamları:** Girilen kelimenin sözlükteki anlamını görüntüler.
- **Örnek Cümleler:** Kelimenin kullanımına dair örnek bir cümle sunar.
- **Benzer Kelime Önerisi:** Girilen kelime sözlükte bulunamazsa, en yakın benzer kelimeyi önerir.

## Kurulum

1. **Gerekli Donanım:**
   - ESP32 Geliştirme Kartı
   - USB bağlantı kablosu

2. **Gerekli Yazılımlar:**
   - [Arduino IDE](https://www.arduino.cc/en/software)
   - ESP32 için Arduino çekirdekleri yüklü olmalıdır. Kurulum için [bu kılavuzu](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html) takip edebilirsiniz.

3. **Projeyi Klonlayın:**
   ```bash
   git clone https://github.com/kullaniciadi/esp32-sozluk-uygulamasi.git
Arduino IDE Ayarları:

Kart Seçimi: Araçlar > Kart > ESP32 Dev Module(Örnek olarak kendi kartınızı seçin normalde)

Port Seçimi: Araçlar > Port > ESP32'nizin bağlı olduğu portu seçin.(Örnek olarak kendi kartınızı seçin normalde)

Kodu Yükleyin:

esp32-sozluk-uygulamasi.ino dosyasını Arduino IDE ile açın.

"Yükle" butonuna basarak kodu ESP32'ye yükleyin.

Kullanım
Seri Monitörü Açın:

Arduino IDE'de Araçlar > Seri Monitör yolunu izleyin.

Baud hızını 115200 olarak ayarlayın.

Kelime Girişi:

Seri monitörde "Anlamadığınız bir kelime yaz:" mesajını gördüğünüzde, anlamını öğrenmek istediğiniz kelimeyi girin ve Enter tuşuna basın.

Sonuçların Görüntülenmesi:

Eğer kelime sözlükte mevcutsa, anlamı ve örnek cümlesi görüntülenecektir.

Eğer kelime bulunamazsa, en yakın benzer kelime önerilecek ve ilgili bilgiler sunulacaktır.

Hiçbir benzer kelime bulunamazsa, "Henüz bu kelime sözlüğümüzde yok, ama üzerinde çalışıyoruz!" mesajı görüntülenecektir.

Katkıda Bulunma
Katkılarınızı memnuniyetle karşılıyoruz! Lütfen önce bir konu açarak değiştirmek istediğiniz konuyu belirtiniz. Büyük değişiklikler için lütfen önce bir tartışma başlatın.

Lisans
Bu proje MIT Lisansı ile lisanslanmıştır. Daha fazla bilgi için LICENSE dosyasına bakabilirsiniz.
