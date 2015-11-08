<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
	
	if($days4bapproval = config_pages_get('tovana_settings','field_approval_days')) {
	  
	  if($node->field_date_event['und'][0]['value']) {
	  $eventtime = strtotime($node->field_date_event['und'][0]['value']);
	  
	    $approvaltime = $eventtime - ($days4bapproval*60*60*24);
		
		if($approvaltime < time()) {
		  print flag_create_link('commerce_line_item', $node->field_product['und'][0]['product_id']);
		  print flag_create_link('commerce_line_item', 6);
		 echo 'flag for approval printed here';
		}
	  }
	}
  ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
