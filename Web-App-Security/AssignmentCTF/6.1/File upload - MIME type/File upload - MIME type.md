# Write up challenge File upload - MIME type

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>


[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/File-upload-MIME-type)<br>
</br>

Truy cập challenge ta thấy đây là hint của challenge:

<img src="./img/0.png" alt="normal_acc_TRAbID"/>

Tiến hành làm theo hint.

- Hint 1: Mục tiêu của bạn là hack thư viện ảnh này bằng cách tải lên mã PHP. Từ đây ta chú ý đến mục upload. Vào xem thử thì thấy challange chỉ cho upload các file với extensions là `.gif`, `.jpeg` và `.png`. 

<img src="./img/00.png" alt="normal_acc_TRAbID"/>

- Hint 2: Truy xuất mật khẩu xác thực trong tệp .passwd ở thư mục gốc của ứng dụng. Kết hợp cả 2 hint ta sẽ có hướng đi như sau: tiến hành upload file shell php với để tương tác và tìm tệp .passwd.

Bài này khá tương tự bài Double extensions chỉ khác ở chỗ là không thể bypass bằng Double extensions nữa, mà bài này có cơ chế kiểm tra qua  Content-Type.

Sau khi search mạng mình sẽ sử dụng shell php tại link sau: 
    https://github.com/flozz/p0wny-shell/blob/master/shell.php

Bắt gói tin Burpsuite kiểm tra thì thấy `Content-Type` được set là `image/png` vì vậy khi up file với đuôi `.jpg` thì sẽ upload thành công tuy nhiên sẽ không nhận dạng và thực thi được file php để get shell. 

<img src="./img/1.png" alt="normal_acc_TRAbID"/>

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

<br>

Thử up với đuôi `.php` thì upload không thành công. 

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

<br>

Bắt gói tin Burpsuite kiểm tra thì thấy `Content-Type` được set là `application/octet-stream`. Đó là nguyên nhân không upload được! 

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

OK vậy bây giờ chỉ cần sửa `Content-Type` thành `image/png` là được.

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

Upload thành công.
Tiến hành nhấp vào file php vừa upload được ta sẽ có được shell.

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

<img src="./img/8.png" alt="normal_acc_TRAbID"/>


Việc tiếp theo là dùng lệnh `ls -la` tìm kiếm trong các thư mục file .passwrd. 
Tiến hành back ra dần thư mục phía trước:

<img src="./img/9.png" alt="normal_acc_TRAbID"/>

Cat file .passwrd đã tìm được và có được flag.

<img src="./img/10.png" alt="normal_acc_TRAbID"/>

Submit thành công!

<img src="./img/11.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** a7n4nizpgQgnPERy89uanf6T4

