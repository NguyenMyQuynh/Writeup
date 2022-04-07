# Write up challenge Javascript - Authentication

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/Javascript-Authentication)<br>
</br>



<br>


Truy cập challenge ta thấy có một form đăng nhập, nhập thử thì thông báo sai hiện lên.

<img src="1.png" alt="normal_acc_TRAbID"/> 

<br>

<div style = "page-break-after: always;"></div>


<br>

Tiến hành inspect, ta thấy button bắt sự kiên onclick và gọi hàm Login.

<img src="2.png" alt="normal_acc_TRAbID"/> 

<br>

Tiến hành xem source code file login.js

<img src="3.png" alt="normal_acc_TRAbID"/> 



<br>

Tại câu điều kiện if, ta thấy user được so sánh với `"4dm1n" `và password được so sánh với `"sh.org"`

<img src="4.png" alt="normal_acc_TRAbID"/> 

<div style = "page-break-after: always;"></div>

<br>


Tiến hành nhập thử, ta nhận được thông báo thành công 

<img src="5.png" alt="normal_acc_TRAbID"/> 

<br>

Dùng password `"sh.org"` submit challenge. Thành công !

<img src="6.png" height="390" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** sh.org