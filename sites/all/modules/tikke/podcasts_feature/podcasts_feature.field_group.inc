<?php
/**
 * @file
 * podcasts_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function podcasts_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contents|node|podcast|form';
  $field_group->group_name = 'group_contents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'podcast';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main';
  $field_group->data = array(
    'label' => 'תכנים',
    'weight' => '5',
    'children' => array(
      0 => 'field_description',
      1 => 'field_podcast_content',
      2 => 'field_podcast_player',
      3 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contents|node|podcast|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|podcast|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'podcast';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'ראשי',
    'weight' => '4',
    'children' => array(
      0 => 'group_contents',
      1 => 'group_podcast_categories',
      2 => 'group_podcast_references',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-main field-group-tabs',
      ),
    ),
  );
  $export['group_main|node|podcast|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_podcast_categories|node|podcast|form';
  $field_group->group_name = 'group_podcast_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'podcast';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main';
  $field_group->data = array(
    'label' => 'קטגוריות רצועת שמע',
    'weight' => '8',
    'children' => array(
      0 => 'field_main_tags',
      1 => 'field_podcast_topic',
      2 => 'field_podcast_quality',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_podcast_categories|node|podcast|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_podcast_references|node|podcast|form';
  $field_group->group_name = 'group_podcast_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'podcast';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main';
  $field_group->data = array(
    'label' => 'הקשרים',
    'weight' => '7',
    'children' => array(
      0 => 'field_teachers_reference',
      1 => 'field_event_reference',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_podcast_references|node|podcast|form'] = $field_group;

  return $export;
}
