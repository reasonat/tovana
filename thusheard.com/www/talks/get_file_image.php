<?php
/*
	This will serve tovana wordpress. 
	get mp3 file image to display in website
*/

header('Access-Control-Allow-Origin: *'); 
require_once('../talks/mp3/getid3/getid3.php');  

//$file = "http://lib.tovana.org.il/Kittisaro and Thanisara/KittisaroAndTanissara2007/Retreat/Day2 - Dharma talk , Kittisaro - The 5 Jhana factors.520.mp3";
//$file = "http://lib.tovana.org.il/Charles Genoud/CG34 Presence Absence 30Sep2012 (Eng).mp3";


$fileUrl = $_POST['fileUrl'];

//$fileUrl = "http://lib.tovana.org.il/guided meditation/Eran Harpaz/Guided meditation, by Eran Harpaz, 15 min.433.mp3";

if(empty($fileUrl)) 
	return false;

//	Fix File path string to local 
$file = str_replace("http://lib.tovana.org.il/",null,$fileUrl);

//	Load ID3 object
$getID3 = new getID3; 
$getID3->option_tag_id3v2 = true;
$getID3->option_tags_images = true;
$getID3->analyze($file);  


if (isset($getID3->info['id3v2']['APIC'][0]['data'])) { 
	   $cover = $getID3->info['id3v2']['APIC'][0]['data']; 
	} elseif (isset($getID3->info['id3v2']['PIC'][0]['data'])) { 
	   $cover = $getID3->info['id3v2']['PIC'][0]['data']; 
	} else { 
	   return false;
	} 
	if (isset($getID3->info['id3v2']['APIC'][0]['image_mime'])) { 
	   $mimetype = $getID3->info['id3v2']['APIC'][0]['image_mime']; 
	} else { 
	   $mimetype = 'image/jpeg';
	}  

	if (!is_null($cover)) {	
		$returnstring = '<img src="data:'.$mimetype.';base64,'.base64_encode($cover).'">'."\n";
		echo $returnstring;
	}
?>