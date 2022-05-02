# Write up challenge Javascript - Obfuscation 1

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/Javascript-Obfuscation-1)<br>
</br>


<br>


Truy cập challenge ta thấy có một form yêu cầu nhập password. Nhập thử thì thông báo sai hiện lên.

<img src="1.png" alt="normal_acc_TRAbID"/> 
<img src="2.png" alt="normal_acc_TRAbID"/> 


<br>

Inspect không thu được thông tin gì nên ta thử Ctr + U xem source code trang 

<img src="3.png" alt="normal_acc_TRAbID"/> 

<br>

<div style = "page-break-after: always;"></div>

<br>

Từ dòng 8 đến dòng 11, ta thấy password nhập vào được so sánh với `unescape(pass)` trong đó pass=`'%63%70%61%73%62%69%65%6e%64%75%72%70%61%73%73%77%6f%72%64'`

Sử dụng Console trong Developer Tools để unescape chuỗi trên để tìm ra password

<img src="4.png" alt="normal_acc_TRAbID"/> 



<br>

Ta tìm được password là `"cpasbiendurpassword"`. Nhập thử và nhận được thông báo thành công

<img src="5.png" alt="normal_acc_TRAbID"/> 
<img src="6.png"  alt="normal_acc_TRAbID"/>

<br>

<div style = "page-break-after: always;"></div>

Dùng password submit challenge. Thành công !

<img src="7.png"  alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** cpasbiendurpassword