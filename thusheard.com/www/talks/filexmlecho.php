<html dir="ltr">

<head>
	<meta charset="UTF-8">
    <meta http-equiv="Content-Type" content="text/html;charset=UTF-8" />
</head>
<body>
<?php 
set_time_limit(0);
require_once('../talks/mp3/getid3/getid3.php'); 
//Initialize getID3 engine
$getID3 = new getID3;
$files = scanDir::scan("../talks/", array("mp3","wav"), true);  

$i = 0;
$id3v2 = 0;
$id3v1 = 0;
$both = 0;
$starttime = microtime(true);   
$xml = new SimpleXMLElement('<data/>');  
foreach($files as $file){  
	if($i < 500) 
	
	{
		$ThisFile = $getID3->analyze($file); 
		echo $file;
		//echo $ThisFile['filenamepath'];
		//$f = $xml->addChild('File');
		//$f->addChild('filename', );
		//$f->addChild('filepath', $ThisFile['filenamepath']); 
		echo "<pre>";
		//print_r($ThisFile);
		echo "</pre>";
		if(isset($ThisFile['comments']['picture']) && 0){
			//var_dump();
			echo $ThisFile['comments']['picture'][0]['image_mime'];
			foreach($ThisFile['comments']['picture'][0] as $key => $value){
				echo $key;
				
			}
			//$echo '<img src="data:'.$ThisFile['comments']['picture'][0]['image_mime'].';base64,'.base64_encode($ThisFile['comments']['picture'][0]['data']).'" />';
			
			$imageinfo = array();
			$imagechunkcheck = getid3_lib::GetDataImageSize($ThisFile['comments']['picture'][0]['data'], $imageinfo);
			print_r($imagechunkcheck);
			$returnstring = '<img src="data:'.$ThisFile['comments']['picture'][0]['image_mime'].';base64,'.base64_encode($ThisFile['comments']['picture'][0]['data']).'" width="'.$imagechunkcheck[0].'" height="'.$imagechunkcheck[1].'">'."\n";
			echo $returnstring;
			/*
			$data = 'data:image/png;base64,AAAFBfj42Pj4';

			list($type, $data) = explode(';', $data);
			list(, $data)      = explode(',', $data);
			$data = base64_decode($data);
			*/
			//file_put_contents('ccimages/image'. $i .'.png', $ThisFile['comments']['picture'][0]['data']);
			
			
			
			echo "<br/>";
			
		}
		
		var_dump($ThisFile->info);
		//var_dump($ThisFile);
		
		$getID3 = new getID3; 
		$getID3->option_tag_id3v2 = true;
		$getID3->option_tags_images = true;
		$getID3->analyze($file); 
		if (isset($getID3->info['id3v2']['APIC'][0]['data'])) { 
		   $cover = $getID3->info['id3v2']['APIC'][0]['data']; 
		} elseif (isset($getID3->info['id3v2']['PIC'][0]['data'])) { 
		   $cover = $getID3->info['id3v2']['PIC'][0]['data']; 
		} else { 
		   $cover = "no_cover"; 
		} 
		if (isset($getID3->info['id3v2']['APIC'][0]['image_mime'])) { 
		   $mimetype = $getID3->info['id3v2']['APIC'][0]['image_mime']; 
		} else { 
		   $mimetype = 'image/jpeg';
		}  

		if (!is_null($cover)) {
			//$f->addChild('mine', $mimetype);
			//$f->addChild('image', $cover);
			//echo $cover; 
			$returnstring = '<img src="data:'.$mimetype.';base64,'.base64_encode($cover).'">'."\n";
			echo $returnstring;
		}
		/*
		
		if(isset($ThisFile['tags_html']['id3v2']['title'][0])){
			$id3v2++;
			foreach($ThisFile['tags_html']['id3v2'] as $key => $tag){ 
				//$f->addChild($key, htmlspecialchars($tag[0]));
			} 
			
		}else if(isset($ThisFile['tags_html']['id3v1']['title'][0])){  
			$id3v1++;
			foreach($ThisFile['tags_html']['id3v1'] as $key => $tag){ 
				//$f->addChild($key, htmlspecialchars($tag[0]));
			}
		}
		 
		if(isset($ThisFile['tags_html']['id3v1']['title'][0]) && isset($ThisFile['tags_html']['id3v2']['title'][0]))
			$both++;
			
		*/
	} 
	$i++; 
}  
 
 echo "<br/>{$i}<br/>";
 $endtime = microtime(true);  
 
 ?>
 
 </body>
 </html>
 <?php
 
 
class scanDir {
    static private $directories, $files, $ext_filter, $recursive;

// ----------------------------------------------------------------------------------------------
    // scan(dirpath::string|array, extensions::string|array, recursive::true|false)
    static public function scan(){
        // Initialize defaults
        self::$recursive = false;
        self::$directories = array();
        self::$files = array();
        self::$ext_filter = false;

        // Check we have minimum parameters
        if(!$args = func_get_args()){
            die("Must provide a path string or array of path strings");
        }
        if(gettype($args[0]) != "string" && gettype($args[0]) != "array"){
            die("Must provide a path string or array of path strings");
        }

        // Check if recursive scan | default action: no sub-directories
        if(isset($args[2]) && $args[2] == true){self::$recursive = true;}

        // Was a filter on file extensions included? | default action: return all file types
        if(isset($args[1])){
            if(gettype($args[1]) == "array"){self::$ext_filter = array_map('strtolower', $args[1]);}
            else
            if(gettype($args[1]) == "string"){self::$ext_filter[] = strtolower($args[1]);}
        }

        // Grab path(s)
        self::verifyPaths($args[0]);
        return self::$files;
    }

    static private function verifyPaths($paths){
        $path_errors = array();
        if(gettype($paths) == "string"){$paths = array($paths);}

        foreach($paths as $path){
            if(is_dir($path)){
                self::$directories[] = $path;
                $dirContents = self::find_contents($path);
            } else {
                $path_errors[] = $path;
            }
        }

        if($path_errors){echo "The following directories do not exists<br />";die(var_dump($path_errors));}
    }

    // This is how we scan directories
    static private function find_contents($dir){
        $result = array();
        $root = scandir($dir);
        foreach($root as $value){
            if($value === '.' || $value === '..') {continue;}
            if(is_file($dir.DIRECTORY_SEPARATOR.$value)){
                if(!self::$ext_filter || in_array(strtolower(pathinfo($dir.DIRECTORY_SEPARATOR.$value, PATHINFO_EXTENSION)), self::$ext_filter)){
                    self::$files[] = $result[] = $dir.DIRECTORY_SEPARATOR.$value;
                }
                continue;
            }
            if(self::$recursive){
                foreach(self::find_contents($dir.DIRECTORY_SEPARATOR.$value) as $value) {
                    self::$files[] = $result[] = $value;
                }
            }
        }
        // Return required for recursive search
        return $result;
    }
}
 
?>