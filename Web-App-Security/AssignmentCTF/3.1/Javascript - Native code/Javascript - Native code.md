# Write up challenge Javascript - Native code

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/Javascript-Native-code)<br>
</br>


<br>


Truy cập challenge ta thấy có một form yêu cầu nhập password. Nhập thử thì không thấy hiện gì.

<img src="1.png" alt="normal_acc_TRAbID"/> 

<img src="2.png" alt="normal_acc_TRAbID"/> 


<br>

<div style = "page-break-after: always;"></div>

<br>


Inspect thử ta thấy có 1 đoạn script lạ không đọc được:

<img src="3.png" alt="normal_acc_TRAbID"/> 

<div style = "page-break-after: always;"></div>

<br>

Tiến hành đặt breakpoint và debug sử dụng step into thử xem thực ra đoạn code này làm gì:


<img src="4.png" alt="normal_acc_TRAbID"/> 



<br>

Step into liên tục cho đến khi form hiện lên yêu cầu nhập pass, nhập vào `"q"`


<img src="5.png"  alt="normal_acc_TRAbID"/>

<br>


Xem biến ta thấy `"q"` ta vừa nhập được lưu vào a. Xem code tại thời điểm đó ta thấy a được so sánh với `"toto123lol"` nếu bằng thông báo `"bravo"`. Vậy `"toto123lol"` là pass cần tìm.

<img src="7.png"  alt="normal_acc_TRAbID"/>

<div style = "page-break-after: always;"></div>

<br>

Dùng flag submit challenge. Thành công !

<img src="8.png" height="390" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** toto123lol