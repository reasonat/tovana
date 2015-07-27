<?php
/**
 * @file
 * simple_page_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function simple_page_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function simple_page_feature_node_info() {
  $items = array(
    'simple_page' => array(
      'name' => t('עמוד רגיל'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
