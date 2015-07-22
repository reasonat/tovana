==============================
Info
==============================

MP3 Player brings the WordPress Audio Player to Drupal. Easily enable the MP3 Player on a CCK FileField.
You can also change any of the WordPress Audio Player settings through an admin interface.

==============================
Upgrading
==============================

Disabled and un-install both MP3 Player and FileField MP3 Player Formatter. Then make any changes you want to
 your default player (?q=admin/settings/mp3player) before applying the formatter to any FileFields or Views.

==============================
Installation
==============================

Watch a video: http://blip.tv/file/1628471

 1. Drop the mp3player folder into the modules directory (/sites/all/modules/)
 2. Download WordPress Audio Standalone Player (http://wpaudioplayer.com/download)
 3. Drop the audio-player.js and player.swf files from the 1pixelout download into mp3player library directory
 (/sites/all/libraries/audio-player/).
 4. Enable MP3 Player module (?q=/admin/build/modules) and optionally FileField MP3 Player Formatter for use with CCK
 5. You can change the player settings (?q=admin/settings/mp3player)

Required Modules:
------------------------------
 - libraries

==============================
Custom Code Use
==============================
Pop this code anywhere to insert an audio player.
<?php print theme('mp3player', 'Default', array('file' => $audio_file_url, 'title' => $audio_title); ?>

==============================
The Future  
==============================
If you have any questions, issues, or feature suggestions then please do leave feedback on the project page
(http://drupal.org/project/mp3player)