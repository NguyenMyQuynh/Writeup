# WebAppSecurity

<br>

## HTML:
![image](https://user-images.githubusercontent.com/62002485/159663472-4f6927cd-1762-4e8a-a15b-368cf4b65f86.png)

![image](https://user-images.githubusercontent.com/62002485/159663505-2fad1a22-6ef6-4d27-865d-52aa3bc69b35.png)

![image](https://user-images.githubusercontent.com/62002485/159663665-d165e459-613e-418b-8ebb-d410048218fe.png)
![image](https://user-images.githubusercontent.com/62002485/159663750-19d9b481-ab92-4edf-be7e-0eda0cad5229.png)

![image](https://user-images.githubusercontent.com/62002485/159664142-3cf5ba2b-66a6-45d9-821c-e110ab81f948.png)

<br>

## JavaScript:
Trong file HTML:
- JS code đặt giữa <script> và </script>
- JS code có thể đặt trong file .js riêng
  - Khai báo trong file HTML cần dùng với thuộc tính src (source) = “URL”: `<script scr='./main.js'>` 
  - Ưu điểm:
      - Tách biệt code với HMTL
      - Dùng lại code
      - Dễ đọc và bảo trì
      - Cache JS để tăng tốc độ load trang
- Thẻ <script> có thể đặt tại `<head>` hoặc `<body>`
  
  ![image](https://user-images.githubusercontent.com/62002485/162554498-901e7b65-677e-45c4-8853-92039bda8e56.png)

  ![image](https://user-images.githubusercontent.com/62002485/162554512-61652911-ebe3-465c-8c33-6edf7c102916.png)
  
  ![image](https://user-images.githubusercontent.com/62002485/162554517-379aa053-76b4-44b3-a18c-e9afb5e760f9.png)

  ![image](https://user-images.githubusercontent.com/62002485/162554580-91e150ec-8601-47a4-989a-b9b4d140d5fe.png)
  
  ![image](https://user-images.githubusercontent.com/62002485/162554589-e8d9e230-1b5f-4ee4-90a9-22e5667eeeba.png)

<br>

## XSS:
  
  https://portswigger.net/web-security/cross-site-scripting
  
  - Reflected XSS: https://portswigger.net/web-security/cross-site-scripting/reflected/lab-html-context-nothing-encoded
  
  <br> Attacker thử nhập input và inspect thì thấy `input được đưa thẳng vào string query url và RESPONSE html trả về mà không kiểm tra`. 
  <br> => Attacker lợi dụng lỗ hổng này để chèn đoạn javascript vào string query url, dụ victim nhấp vào và script được chèn vào response html và thực thi trên browser victim. 
  
  ![image](https://user-images.githubusercontent.com/62002485/162554725-0203f0bb-d359-46fd-89b6-956b7f4b4dae.png)

  ![image](https://user-images.githubusercontent.com/62002485/162554740-a80dc810-ec43-49c0-bd3f-353b5d812940.png)
  
  ![image](https://user-images.githubusercontent.com/62002485/162554782-5aca2391-ad2e-446b-91cd-45daf6e833a3.png)

  <br>
    
  - Stored XSS: https://portswigger.net/web-security/cross-site-scripting/stored/lab-html-context-nothing-encoded
  
    <br> Attacker thử nhập input và inspect thì thấy `input được lưu thẳng vào cơ sở dữ liệu mà không kiểm tra và sau đó render lên nếu có request truy cập trang đó`. 
  <br> => Attacker lợi dụng lỗ hổng này để chèn đoạn javascript lưu trữ vào cơ sở dữ liệu, khi victim truy cập trang html đã bị lưu đoạn js độc hại, đoạn js đó sẽ được thực thi trên browser victim.
  
  ![image](https://user-images.githubusercontent.com/62002485/162554863-fb42d249-44cd-4c47-92fa-1c6d811fc218.png)

  ![image](https://user-images.githubusercontent.com/62002485/162554924-e4bd9684-2581-4607-85e3-a6fc3ec839be.png)

  ![image](https://user-images.githubusercontent.com/62002485/162554970-a3d2ed68-6841-49b3-8764-f8744f74d329.png)

  ![image](https://user-images.githubusercontent.com/62002485/162555020-2986cb87-5c78-4c89-b712-96925935c7a5.png)

  <br>
  
  - DOM Based XSS: https://portswigger.net/web-security/cross-site-scripting/dom-based/lab-document-write-sink
  
    
  <br> Attacker thử nhập input và inspect thì thấy `response chứa đoạn js get query string url(input) và ghi chúng thẳng vào DOM trong 1 thẻ img mà không kiểm tra`. 
  <br> => Attacker lợi dụng lỗ hổng này để chèn đoạn javascript vào(đóng thẻ img hoặc đóng attribute thẻ img sau đó chèn lệnh js), dụ victim nhấp vào url để chạy đoạn script sau đó một img được chèn vào html và lệnh js độc hại được thực thi trên browser victim. 
  
  ![image](https://user-images.githubusercontent.com/62002485/162555165-6529dfd9-50db-4436-ad33-4bf49d380100.png)

  https://developer.mozilla.org/en-US/docs/Web/API/URLSearchParams
  ![image](https://user-images.githubusercontent.com/62002485/162555397-e7e18fa9-f024-44a7-b988-f774935078dd.png)

  ![image](https://user-images.githubusercontent.com/62002485/162555426-f7732dfc-c082-4ac3-bc32-2a8611caa732.png)

  ![image](https://user-images.githubusercontent.com/62002485/162555472-c71c9b90-f089-45b4-b486-fa853b481ff1.png)

  ![image](https://user-images.githubusercontent.com/62002485/162555485-710f66a7-5e50-4bd9-9e71-50747c471f81.png)

  ![image](https://user-images.githubusercontent.com/62002485/162555512-30e4ad39-5250-475a-b260-0dae84005061.png) 
  
  ![image](https://user-images.githubusercontent.com/62002485/162555204-1a46cf90-f683-4d83-9920-b429392df282.png)
  
  ![image](https://user-images.githubusercontent.com/62002485/162555642-5ab40152-d364-4a33-aeff-33c5c863528f.png)
  
  ![image](https://user-images.githubusercontent.com/62002485/162555681-47a9ba06-c773-4df6-a9f2-4b12c06739df.png)
  
  <br>
  
## SQL injection:
  
  https://portswigger.net/web-security/sql-injection
  https://portswigger.net/web-security/sql-injection/cheat-sheet
  https://portswigger.net/web-security/sql-injection/examining-the-database
  
  
 ## File inclusion

https://portswigger.net/web-security/file-path-traversal
  
ftp
<br>xampp


https://quantrimang.com/file-etc-passwd-la-gi-181275

![image](https://user-images.githubusercontent.com/62002485/164264184-986a86c0-065b-4749-8f54-4b9a6efb0d42.png)

![image](https://user-images.githubusercontent.com/62002485/164264288-c6ba7691-94ec-4ce3-b9fe-d4105d6439b4.png)

https://www.w3schools.com/php/php_includes.asp

https://www.w3schools.com/php/php_superglobals_get.asp
https://www.w3schools.com/php/php_forms.asp

https://www.w3schools.com/php/func_var_isset.asp

https://www.w3schools.com/php/php_operators.asp

https://khaidantri.net/win-ini-la-gi

Encode to URL-encoded format:
  - https://www.urlencoder.org/
  - https://www.w3schools.com/tags/ref_urlencode.asp

![image](https://user-images.githubusercontent.com/62002485/164257325-7eef96a3-148f-4333-ba9d-19b91b8dab7e.png)

![image](https://user-images.githubusercontent.com/62002485/164257616-3479092f-0657-4a09-8173-e9c5d5386cc5.png)

Decode from URL-encoded format: https://www.urldecoder.org/

https://webcoban.vn/php/cach-tao-va-chay-mot-tap-tin-php.html

https://www.thegioididong.com/hoi-dap/xampp-la-gi-cach-cai-dat-va-su-dung-localhost-tren-may-1339338




