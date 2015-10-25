/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

/**********  scroll  ************/

$(document).ready(function(){       
      $scroll_pos = 0;
      $(document).scroll(function() { 
        $scroll_pos = $(this).scrollTop();
        if($scroll_pos > 0) {
            $("body").addClass('scroll');
        }
        else {
            $("body").removeClass('scroll');
        }
      });
});

$(".menu-button").click(function(){
  if ($("body").hasClass("display-menu")){
    $("body").removeClass("display-menu");
  }
  else {
    $("body").addClass("display-menu");
  }
});

$( ".page-user .tabs-primary" ).prepend( "<h2 class='block__title block-title block-title-user en'><span>User Menu</span></h2><h2 class='block__title block-title block-title-user he'><span>תפריט משתמש</span></h2>" );


}
};
})(jQuery, Drupal, this, this.document);
