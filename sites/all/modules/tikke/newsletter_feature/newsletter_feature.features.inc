<?php
/**
 * @file
 * newsletter_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function newsletter_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function newsletter_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function newsletter_feature_node_info() {
  $items = array(
    'newsletter' => array(
      'name' => t('עלון'),
      'base' => 'node_content',
      'description' => t('עלון התובנה העליונה'),
      'has_title' => '1',
      'title_label' => t('כותרת'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
