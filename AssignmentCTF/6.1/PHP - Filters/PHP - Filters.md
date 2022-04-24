# Write up challenge PHP - Filters


Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/PHP-Filters)<br>
</br>

Challenge yêu cầu tìm mật khẩu admin.

Truy cập challenge ta thấy có một trang home và một trang login với các url như sau:

<img src="./img/1.png" height=350 alt="normal_acc_TRAbID"/> 

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

Tên đề bài đã gợi ý quá rõ ràng là PHP - Filters, sau khi search tìm hiểu, em biết là php-filters có thể được sử dụng để xem source files cục bộ máy chủ với output là base64 với cú pháp: `vuln.php?page=php://filter/convert.base64-encode/resource=filepath`
<br>Từ url 2 trang trên thì ta có biết được 2 file là `accueil.php` và `login.php`. Tiến hành áp dụng php-filters để xem source 2 file này:
- accueil.php:

        ?inc=php://filter/convert.base64-encode/resource=accueil.php

<img src="./img/03.png" alt="normal_acc_TRAbID"/>

Decode ta chưa tìm thấy thông tin gì quan trọng:

<img src="./img/033_1.png" alt="normal_acc_TRAbID"/>

<div style = "page-break-after: always;"></div>

- Tiếp tục với file login.php:

        ?inc=php://filter/convert.base64-encode/resource=login.php  

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

Decode ta thấy được nội dung file login.php. Đọc code ta thấy `user` và `pass` người dùng nhập vào được so sánh với 2 biến `$username` và `$password`, tuy nhiên trong file này thì không thấy 2 biến đó được định nghĩa. Để ý ta thấy có câu lệnh `include("config.php");` ở phần đầu, có thể 2 biến này đã được định nghĩa ở đây.
<br>OK, bây giờ ta sẽ tiến hành áp dụng php-filters để xem source file config.php:

    ?inc=php://filter/convert.base64-encode/resource=config.php

<br>

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

Decode ta nhận được user và pass admin:

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

Sử dụng user và pass tìm được login tại trang login:

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

Login thành công! 

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

Dùng pass admin submit!

<img src="./img/8.png" height=350 alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** DAPt9D2mky0APAF

