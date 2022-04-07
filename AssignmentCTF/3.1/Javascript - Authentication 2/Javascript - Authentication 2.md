# Write up challenge Javascript - Authentication 2

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/Javascript-Authentication-2)<br>
</br>


<br>


Truy cập challenge ta thấy có một button login, nhấp vào yêu cầu nhập lần lượt username và password. Nhập thử thì thông báo sai hiện lên.

<img src="1.png" alt="normal_acc_TRAbID"/> 
<img src="2.png" alt="normal_acc_TRAbID"/> 
<img src="3.png" alt="normal_acc_TRAbID"/> 
<img src="4.png" alt="normal_acc_TRAbID"/> 

<br>

Tiến hành inspect, ta thấy button bắt sự kiên onclick và gọi hàm connexion().

<img src="5.png" alt="normal_acc_TRAbID"/> 

<br>

<div style = "page-break-after: always;"></div>

Tiến hành xem source code file login.js.
<br>
Từ dòng 4 đến dòng 15, ta thấy username và password được so sánh với 2 biến TheUsername và ThePassword được tạo từ biến TheSplit `"GOD:HIDDEN"` và được phân chia bởi dấu `":"`

<img src="6.png" alt="normal_acc_TRAbID"/> 



<br>
<br>

Tiến hành nhập username là `"GOD"` và password là `"HIDDEN"`, ta nhận được thông báo thành công 

<img src="7.png" alt="normal_acc_TRAbID"/> 
<img src="8.png" alt="normal_acc_TRAbID"/> 
<img src="9.png" alt="normal_acc_TRAbID"/> 

<br>

Dùng password submit challenge. Thành công !

<img src="10.png"  alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** HIDDEN