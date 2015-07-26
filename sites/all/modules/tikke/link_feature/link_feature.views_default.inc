<?php
/**
 * @file
 * link_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function link_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'main_links_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'היבט קישורים';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'היבט קישורים';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'התאמה';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'איתחול';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'מיין לפי';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'עולה';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'יורד';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'מספר פריטים בעמוד';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- הכל -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'היסט';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« לעמוד הראשון';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ לעמוד הקודם';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'לעמוד הבא ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'לעמוד האחרון »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: קטגורית קישור (field_link_category) */
  $handler->display->display_options['relationships']['field_link_category_tid']['id'] = 'field_link_category_tid';
  $handler->display->display_options['relationships']['field_link_category_tid']['table'] = 'field_data_field_link_category';
  $handler->display->display_options['relationships']['field_link_category_tid']['field'] = 'field_link_category_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'link' => 'link',
  );

  /* Display: קישורים */
  $handler = $view->new_display('block', 'קישורים', 'block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: קטגורית קישור (field_link_category) */
  $handler->display->display_options['relationships']['field_link_category_tid']['id'] = 'field_link_category_tid';
  $handler->display->display_options['relationships']['field_link_category_tid']['table'] = 'field_data_field_link_category';
  $handler->display->display_options['relationships']['field_link_category_tid']['field'] = 'field_link_category_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: תקציר קישור */
  $handler->display->display_options['fields']['field_link_description']['id'] = 'field_link_description';
  $handler->display->display_options['fields']['field_link_description']['table'] = 'field_data_field_link_description';
  $handler->display->display_options['fields']['field_link_description']['field'] = 'field_link_description';
  $handler->display->display_options['fields']['field_link_description']['label'] = '';
  $handler->display->display_options['fields']['field_link_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_link_description']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: קישור */
  $handler->display->display_options['fields']['field_link_main']['id'] = 'field_link_main';
  $handler->display->display_options['fields']['field_link_main']['table'] = 'field_data_field_link_main';
  $handler->display->display_options['fields']['field_link_main']['field'] = 'field_link_main';
  $handler->display->display_options['fields']['field_link_main']['label'] = 'קישור לאתר';
  $handler->display->display_options['fields']['field_link_main']['click_sort_column'] = 'url';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'link' => 'link',
  );
  /* Filter criterion: Content: קטגורית קישור (field_link_category) */
  $handler->display->display_options['filters']['field_link_category_tid']['id'] = 'field_link_category_tid';
  $handler->display->display_options['filters']['field_link_category_tid']['table'] = 'field_data_field_link_category';
  $handler->display->display_options['filters']['field_link_category_tid']['field'] = 'field_link_category_tid';
  $handler->display->display_options['filters']['field_link_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['operator_id'] = 'field_link_category_tid_op';
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['label'] = 'קטגורית קישור';
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['operator'] = 'field_link_category_tid_op';
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['identifier'] = 'field_link_category_tid';
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_link_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_link_category_tid']['vocabulary'] = 'link_categories';
  $handler->display->display_options['block_description'] = 'link block';

  /* Display: עמוד ניהול */
  $handler = $view->new_display('page', 'עמוד ניהול', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'שינוי ערכים',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'תאריך פירסום';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'מחק קישור';
  $handler->display->display_options['fields']['delete_node']['element_type'] = 'strong';
  $handler->display->display_options['fields']['delete_node']['text'] = 'מחיקה';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'ערוך קישור';
  $handler->display->display_options['fields']['edit_node']['text'] = 'עריכה';
  /* Field: Content: קטגורית קישור */
  $handler->display->display_options['fields']['field_link_category']['id'] = 'field_link_category';
  $handler->display->display_options['fields']['field_link_category']['table'] = 'field_data_field_link_category';
  $handler->display->display_options['fields']['field_link_category']['field'] = 'field_link_category';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'קישור';
  $handler->display->display_options['fields']['view_node']['text'] = 'לעמוד הקישור';
  /* Field: Content: קישור */
  $handler->display->display_options['fields']['field_link_main']['id'] = 'field_link_main';
  $handler->display->display_options['fields']['field_link_main']['table'] = 'field_data_field_link_main';
  $handler->display->display_options['fields']['field_link_main']['field'] = 'field_link_main';
  $handler->display->display_options['fields']['field_link_main']['label'] = 'קישור לאתר חיצוני';
  $handler->display->display_options['fields']['field_link_main']['click_sort_column'] = 'url';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'מפורסם';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'link' => 'link',
  );
  /* Filter criterion: Content: קטגורית קישור (field_link_category) */
  $handler->display->display_options['filters']['field_link_category_tid']['id'] = 'field_link_category_tid';
  $handler->display->display_options['filters']['field_link_category_tid']['table'] = 'field_data_field_link_category';
  $handler->display->display_options['filters']['field_link_category_tid']['field'] = 'field_link_category_tid';
  $handler->display->display_options['filters']['field_link_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['operator_id'] = 'field_link_category_tid_op';
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['label'] = 'קטגורית קישור';
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['operator'] = 'field_link_category_tid_op';
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['identifier'] = 'field_link_category_tid';
  $handler->display->display_options['filters']['field_link_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_link_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_link_category_tid']['vocabulary'] = 'link_categories';
  $handler->display->display_options['path'] = 'link-managment';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'ניהול קישורים';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-menu-manager';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['main_links_view'] = array(
    t('Master'),
    t('היבט קישורים'),
    t('more'),
    t('התאמה'),
    t('איתחול'),
    t('מיין לפי'),
    t('עולה'),
    t('יורד'),
    t('מספר פריטים בעמוד'),
    t('- הכל -'),
    t('היסט'),
    t('« לעמוד הראשון'),
    t('‹ לעמוד הקודם'),
    t('לעמוד הבא ›'),
    t('לעמוד האחרון »'),
    t('term from field_link_category'),
    t('קישורים'),
    t('קישור לאתר'),
    t('קטגורית קישור'),
    t('link block'),
    t('עמוד ניהול'),
    t('- Choose an operation -'),
    t('שינוי ערכים'),
    t('תאריך פירסום'),
    t('מחק קישור'),
    t('מחיקה'),
    t('ערוך קישור'),
    t('עריכה'),
    t('קישור'),
    t('לעמוד הקישור'),
    t('קישור לאתר חיצוני'),
    t('מפורסם'),
  );
  $export['main_links_view'] = $view;

  return $export;
}
