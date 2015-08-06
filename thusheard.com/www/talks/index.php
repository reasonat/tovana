<?php
/* VESPA 0.8.5 - VEry Simple Parser for directories with Audio files - 30.10.2011
   by Dieter Willinger - http://vespa.willinger.cc - released under the GNU Public License.
*******************************************************************************************/

$then = microtime(true);			// VESPA detects time when start building the page for info in debug mode

$version = '0.8.5';			// VESPA Version
require_once('vespa/config.php');		// VESPA includes the configuration file
require_once('vespa/getid3/getid3.php');	// VESPA includes the getID3 library

// VESPA checks and explores all necessary directories
if (isset($_GET['dir'])) $weburl = $_GET['dir'];			// VESPA reads the URI
$weburl = '/' . $weburl;
$replacement = '';
$getcwd = getcwd();							// VESPA checks out the working directory
	if ($weburl != '') { 						// VESPA purges the URI to ensure security
		$weburl = str_replace( '/..', $replacement, $weburl); 	
		$weburl = str_replace( '\..', $replacement, $weburl); 	
		$weburl = str_replace( '\\..', $replacement, $weburl); 	
	}	
	if (empty($absolute_dir)) { $absolute_dir = $getcwd; } 		// If no value was handed over the directory is set
$absolute_dir = realpath($getcwd . $weburl);				// Absolute path without '/..' to the MP3s is built
    if (! is_dir($absolute_dir)) { 
		$direrror = 1; 
		$absolute_dir = realpath($getcwd);
	} 
$weburl = str_replace($getcwd, $replacement, $absolute_dir);		// VESPA extracts the Web-URL from the absolute path to have a nice URL to pass on
$dir = opendir($absolute_dir); 						// VESPA opens the absolute directory
$domain = $_SERVER['SERVER_NAME']; 					// The domain is found
$maindirectory = $_SERVER['PHP_SELF'];
$scriptplace = $_SERVER['SCRIPT_FILENAME'];				// The name of this script is found

$scriptname = str_replace($getcwd, $replacement, $scriptplace); 	// The exact name of this script is extracted
$webdir = str_replace($scriptname, $replacement, $maindirectory); 	// The name of the web directory containing this script is extracted
$testrun = $absolute_dir . $scriptname; 				// VESPA builds a possible location for this script for a later check whether true
$basename = basename($absolute_dir);
$parent_weburl = str_replace($basename, $replacement, $weburl);		// VESPA builds URI for parent directory
$dirparameter = 'dir=' . $weburl;

// VESPA determines whether the current directory contains an individual config.php
$configfile = $absolute_dir . '/config.php';
	if (file_exists($configfile)) { require_once($configfile); }

// VESPA checks out the whole file sort order thing
	if (isset($_GET['filesortorder'])) {$filesortorder = $_GET['filesortorder']; }
	else { 															// VESPA uses config settings if no parameter for sort order was passed on	
		$filesortorder = $defaultfilesortorder; 
		$nosortpassedon = 1;
		}	
	if ($filesortorder != 'title' AND $filesortorder != 'artist' AND $filesortorder != 'filename' AND $filesortorder != 'filedate-desc' AND $filesortorder != 'filedate-asc' AND $filesortorder != 'random') { $filesortorder = 'filename'; }	// VESPA sets fall back if parameter does not exist
	if ($nosortpassedon != 1) { $sortparameter = '&filesortorder='.$filesortorder; }				// VESPA builds a parameter to pass on

// VESPA applies language settings
	if (isset($_GET['lang'])) { 
		$language = $_GET['lang']; 
		}				// VESPA uses config settings if no parameter for language was passed on
	else { 
		if ($defaultlanguage != '') { $language = $defaultlanguage;}
		else { $language = substr($_SERVER['HTTP_ACCEPT_LANGUAGE'], 0, 2); }
		$nolangpassedon = 1;
		}	
	if ($language == 'en') { $languagefile = 'vespa/languages/en.inc.php'; }
	elseif ($language == 'fr') { $languagefile = 'vespa/languages/fr.inc.php'; }
	elseif ($language == 'es') { $languagefile = 'vespa/languages/es.inc.php'; }
	elseif ($language == 'it') { $languagefile = 'vespa/languages/it.inc.php'; }
	elseif ($language == 'et') { $languagefile = 'vespa/languages/et.inc.php'; }
	elseif ($language == 'de') { $languagefile = 'vespa/languages/de.inc.php'; }
	else { $languagefile = 'vespa/languages/en.inc.php'; }
	if (! file_exists($languagefile)) { 		// VESPA checks whether the file actually exists
		if (! file_exists('vespa/languages/en.inc.php')) { exit('Fatal Error - VESPA could not detect any language files. Please check whether you copied all directories and files of VESPA to your web space.'); }				
					}	
	if ($nolangpassedon != 1) { $langparameter = '&lang='.$language; }	// VESPA builds a parameter to pass on
	include $languagefile;												// VESPA sets the language for the front end to display messages

// VESPA applies the theme
	if (! file_exists($theme.'/style.css')) {
		$theme = 'vespa/themes/silver';
			if (! file_exists($theme.'/style.css')) { echo $msg_notheme; }
		}

// Passing on 'debug' as parameter shows several of the variables set above
	if (isset($_GET['debug'])) { include('vespa/includes/debug-param.inc.php'); }

// VESPA determines output here =======================================
if ((isset($_GET['rss'])) AND (!isset($_GET['debug']))) { include 'vespa/includes/rss.inc.php'; exit ();	}	// VESPA shows RSS if attached to URL 
else { include $theme.'/template.inc.php'; }						// VESPA shows the common template

	// Passing on 'debug' as parameter shows several variables and the phpinfo
	if (isset($_GET['debug'])) {
		if ($allowdebug == true) { include 'vespa/includes/debug-phpinfo.inc.php'; }
		else { echo '<div class=\'errormessage\'>'.$msg_nodebugmode.'</div>'; }
	}
?>

