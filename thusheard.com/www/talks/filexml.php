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
		
	
		$ThisFile = $getID3->analyze($file); 
		$f = $xml->addChild('File');
		$f->addChild('filename', $ThisFile['filename']);
		$f->addChild('filepath', $ThisFile['filenamepath']); 
		if(isset($ThisFile['tags_html']['id3v2']['title'][0]))
		{
			$id3v2++;
			foreach($ThisFile['tags_html']['id3v2'] as $key => $tag){ 
				$f->addChild($key, htmlspecialchars($tag[0]));
			} 
			
		}
		else if(isset($ThisFile['tags_html']['id3v1']['title'][0]))
		{  
			$id3v1++;
			foreach($ThisFile['tags_html']['id3v1'] as $key => $tag){ 
				$f->addChild($key, htmlspecialchars($tag[0]));
			}
		}
		 
		if(isset($ThisFile['tags_html']['id3v1']['title'][0]) && isset($ThisFile['tags_html']['id3v2']['title'][0]))
			$both++;
	 

//	$i++; 
//	if ($i > 15) break; 
}
header("Content-Type: text/xml"); 
echo $xml->saveXML();

//echo $i;
 
 
 
 
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