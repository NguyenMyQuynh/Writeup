# Write up challenge SQL injection - Authentication - GBK

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/SQL-injection-authentication-GBK)<br>
</br>

Mục tiêu ta cần làm là nhận được quyền truy cập admin. Thử thực hiện attack:  

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

Thông báo không thành công. 

<img src="./img/2.png" alt="normal_acc_TRAbID"/> 

Để ý tên challenge và titile đã cho, sau khi đi tìm hiểu GBK, biết được đó dùng để mã hóa chuỗi tiếng Trung, dùng để bypass addslashes() Function.
<br> Về addslashes(), nó sẽ thêm kí tự `\` vào trước các kí tự đặc biệt như `'`. Đó là lí do dấu `'` của chúng ta chèn vào bị escape và attack không được. 


<img src="./img/3.png" alt="normal_acc_TRAbID"/>

Từ đó ý tưởng là chúng ta chèn kí tự nào đó sao cho khi addslashes() Function thực thi xong thì kí tự `\` được thêm vào sẽ kết hợp với kí tự của chúng ta tạo thành một GBK hợp lệ.

<br> Ở đây mình sẽ chọn `%aa%5c`. Login cuối cùng sẽ là: `%aa%27 or 1=1--` và sau khi thực thi addlash sẽ thành `%aa%5c%27 or 1=1--` hay `猏' or 1=1--`

<img src="./img/4.png" height=350 alt="normal_acc_TRAbID"/>

<div style = "page-break-after: always;"></div>

Dùng burpsuit sửa request 

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

<div style = "page-break-after: always;"></div>

Forward và nhận được flag:

<img src="./img/7.png" alt="normal_acc_TRAbID"/>


Submit thành công 

<img src="./img/9.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** iMDaFlag1337!
