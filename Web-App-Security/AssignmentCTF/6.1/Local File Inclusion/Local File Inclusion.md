# Write up challenge Local File Inclusion

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/Local-File-Inclusion)<br>
</br>

Truy cập challenge ta thấy có 6 tab  | sysadm | reseau | esprit | crypto | coding | archives |.

<img src="./img/1.png" alt="normal_acc_TRAbID"/>

Bên phải có link admin nhấp vào thì yêu cầu user và pass!

<img src="./img/t1.png" alt="normal_acc_TRAbID"/>

Bấm chọn từng tab thử thì ta thấy tương ứng với từng tab là thư mục chứa các file, đồng thời ta thấy url thay đổi, có thêm tham số `?files=sysadm`

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

<div style = "page-break-after: always;"></div>

Tiếp tục chọn file thì url có thêm tham số `?files=sysadm&f=index.html`. Từ đó ta có thể thấy tham số trên URL: `?files=sysadm&f=index.html`:
- files: tên thư mục
- f: tên file trong thư mục

<img src="./img/t2.png" alt="normal_acc_TRAbID"/>

Tiến hành thử một attack đơn giản: `http://challenge01.root-me.org/web-serveur/ch16/?files=../`
<br> Thật vậy, có lỗi Local File Inclusion!

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

Ta thấy thư mục admin, vào xem thử: `http://challenge01.root-me.org/web-serveur/ch16/?files=../admin`

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

Có file index.php. Ta Tiến hành nhấp vào xem source code, url tương ứng `http://challenge01.root-me.org/web-serveur/ch16/?files=../admin&f=index.php` thấy được user và password admin.

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

Dùng user và pass vừa tìm được truy cập vào link admin bên phải thì thành công.
<img src="./img/6.png" alt="normal_acc_TRAbID"/>

Submit flag! 

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** OpbNJ60xYpvAQU8
