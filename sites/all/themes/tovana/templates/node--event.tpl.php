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
  ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>

 <script type="text/javascript" src="https://addevent.com/libs/atc/1.6.1/atc.min.js"></script> 
 <div title="Add to Calendar" class="addeventatc">
    Add to Calendar
    <span class="start">11/15/2015 09:00 AM</span>
    <span class="end">11/15/2015 11:00 AM</span>
    <span class="timezone">Europe/Paris</span>
    <span class="title">Summary of the event</span>
    <span class="description">Description of the event<br>Example of a new line</span>
    <span class="location">Location of the event</span>
    <span class="organizer">Organizer</span>
    <span class="organizer_email">Organizer e-mail</span>
    <span class="facebook_event">https://www.facebook.com/events/703782616363133</span>
    <span class="all_day_event">false</span>
    <span class="date_format">MM/DD/YYYY</span>
</div> 