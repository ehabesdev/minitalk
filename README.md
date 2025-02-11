# 💬 Minitalk

**Minitalk**, Unix sinyalleri kullanarak prosesler arası iletişim (IPC) üzerine odaklanan bir projedir. Sinyaller gönderip alarak birbirleriyle iletişim kurabilen bir istemci ve sunucu programı oluşturmayı içerir.

## ⚙️ Nasıl Çalışır?

İstemci programı, girdi olarak bir mesaj ve sunucunun işlem kimliğini (PID) alır. Ardından, mesajın her karakterini ikili gösterimine kodlar. İkili gösterimdeki her bit için istemci, sunucuya belirli bir sinyal gönderir (örneğin, 0 için SIGUSR1, 1 için SIGUSR2).

Sunucu programı, gelen sinyalleri dinleyen bir sinyal işleyicisine sahiptir. Alınan sinyalleri çözer, karakterleri yeniden oluşturur ve sonunda tüm mesajı yazdırır.

## 📁 Proje Yapısı

* **client.c:** İstemci programının uygulanması.
* **server.c:** Sunucu programının uygulanması.
* **libft/:** Projede kullanılan standart C kütüphane fonksiyonlarının özel uygulamalarını içeren bir dizin.

## 🚀 Başlarken

1. **Depoyu klonlayın:**

   ```bash
   git clone git@github.com:ehabesdev/minitalk.git

3. **Programları derleyin:**

    ```bash
   make
   ```

5. **Sunucuyu çalıştırın:**

   ```bash
   ./server
   ```

Bu, sunucunun işlem kimliğini (PID) konsola yazdıracaktır.

4. **İstemciyi çalıştırın:**

```bash
./client <server_PID> <message>
//<server_PID> yerine sunucunun gerçek PID'sini ve <message> yerine göndermek istediğiniz mesajı yazın.
```
# ✏️ Kullanım Örneği

```bash
# Sunucuyu çalıştırın./server
# Çıktı: process id: 12345
# İstemciyi çalıştırın./client 12345 "Merhaba dünya!"
```
Sunucu daha sonra alınan mesajı çıktı olarak verecektir:

```bash
Merhaba dünya!
```
## ✨ Özellikler

* Sinyaller kullanarak temel IPC.
* Karakter kodlama ve çözme.
* Özel kütüphane fonksiyonları (libft).

## 🤔 Karşılaşılan Zorluklar

* **Sinyal İşleme:** Unix'te sinyal işleme mekanizmalarını anlama ve uygulama.
* **Senkronizasyon:** Veri bozulmasını önlemek için istemci ve sunucu arasında uygun senkronizasyon sağlama.
* **Hata İşleme:** Beklenmeyen durumlarla başa çıkmak için güçlü hata işleme uygulama.

## 💡 Öğrenme Çıktıları

* **Prosesler Arası İletişim:** IPC kavramlarını ve tekniklerini daha derinlemesine anlama.
* **Unix Sinyalleri:** Prosesler arasında iletişim için Unix sinyallerinin nasıl kullanılacağını öğrenme.
* **C Programlama:** Özellikle bit manipülasyonu ve sinyal işleme gibi alanlarda C programlama becerilerini geliştirme.

## 📜 Lisans

Bu proje MIT Lisansı altında lisanslanmıştır - ayrıntılar için LICENSE dosyasına bakın.

## 🙏 Teşekkürler

* Bu proje üzerinde çalışma fırsatı sağladığı için 42 Okulu'na teşekkürler.
* Kavramları anlamama yardımcı olan çevrimiçi kaynaklara ve öğreticilere teşekkürler.
