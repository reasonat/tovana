<?php
/**
 * @file
 * articles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function articles_ctools_plugin_api($module = NULL, $api = NULL) {
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
function articles_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function articles_node_info() {
  $items = array(
    'article' => array(
      'name' => t('מאמר'),
      'base' => 'node_content',
      'description' => t('השתמשו ב<em>מאמרים</em> עבור תכנים תלויי זמן כמו חדשות, הודעות לעיתונות או הודעות בבלוג.'),
      'has_title' => '1',
      'title_label' => t('כותרת'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
