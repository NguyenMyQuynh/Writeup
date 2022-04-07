# Write up challenge Javascript - Obfuscation 2

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/Javascript-Obfuscation-2)<br>
</br>


<br>


Truy cập challenge ta thấy một trang trống.

<img src="1.png" alt="normal_acc_TRAbID"/> 



<br>

Tiến hành inspect thử, ta thấy có một biến `pass` được gán bằng `unescape("unescape%28%22String.fromCharCode%2528104%252C68%252C117%252C102%252C106%252C100%252C107%252C105%252C49%252C53%252C54%2529%22%29");`

<img src="2.png" alt="normal_acc_TRAbID"/> 

<br>
<br>
<br>

Sử dụng Console trong Developer Tools để unescape chuỗi trên

<img src="3.png" alt="normal_acc_TRAbID"/> 

<br>

<div style = "page-break-after: always;"></div>

<br>


Tiếp tục unescape 

<img src="4.png" alt="normal_acc_TRAbID"/> 

<br>

Tiếp tục thực thi chuỗi vừa thu được, ta thu được một chuỗi kí tự có vẻ như pass là `"hDufjdki156"`

<img src="5.png" alt="normal_acc_TRAbID"/> 

<br>



Dùng chuỗi đó submit challenge. Thành công !

<img src="6.png" height="390" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** hDufjdki156