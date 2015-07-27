<?php
/**
 * @file
 * podcasts_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function podcasts_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'podcasts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'רצועותת השמע';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'רצועות השמע';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['id'] = 'field_teachers_reference_target_id';
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['table'] = 'field_data_field_teachers_reference';
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['field'] = 'field_teachers_reference_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: תקציר */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: איכות רצועת שמע */
  $handler->display->display_options['fields']['field_podcast_quality']['id'] = 'field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['table'] = 'field_data_field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['field'] = 'field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_quality']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'להמשך קריאה >';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'לעמוד התרומות >';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/397';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
    'podcast' => 'podcast',
  );
  /* Filter criterion: Content: מורים (field_teachers_reference) */
  $handler->display->display_options['filters']['field_teachers_reference_target_id']['id'] = 'field_teachers_reference_target_id';
  $handler->display->display_options['filters']['field_teachers_reference_target_id']['table'] = 'field_data_field_teachers_reference';
  $handler->display->display_options['filters']['field_teachers_reference_target_id']['field'] = 'field_teachers_reference_target_id';
  $handler->display->display_options['filters']['field_teachers_reference_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_teachers_reference_target_id']['expose']['operator_id'] = 'field_teachers_reference_target_id_op';
  $handler->display->display_options['filters']['field_teachers_reference_target_id']['expose']['label'] = 'מורים (field_teachers_reference)';
  $handler->display->display_options['filters']['field_teachers_reference_target_id']['expose']['operator'] = 'field_teachers_reference_target_id_op';
  $handler->display->display_options['filters']['field_teachers_reference_target_id']['expose']['identifier'] = 'field_teachers_reference_target_id';

  /* Display: רצועות השמע */
  $handler = $view->new_display('page', 'רצועות השמע', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['id'] = 'field_teachers_reference_target_id';
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['table'] = 'field_data_field_teachers_reference';
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['field'] = 'field_teachers_reference_target_id';
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['label'] = 'משתמש entity referenced from field_teachers_reference';
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
    'podcast' => 'podcast',
  );
  /* Filter criterion: Content: מורים (field_teachers_reference) (reference filter) */
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['id'] = 'field_teachers_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['table'] = 'field_data_field_teachers_reference';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['field'] = 'field_teachers_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['operator_id'] = 'field_teachers_reference_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['label'] = 'מורים';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['operator'] = 'field_teachers_reference_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['identifier'] = 'field_teachers_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['reference_display'] = 'teachers_reference:entityreference_1';
  /* Filter criterion: Content: אירוע (field_event_reference) (reference filter) */
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['id'] = 'field_event_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['table'] = 'field_data_field_event_reference';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['field'] = 'field_event_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['operator_id'] = 'field_event_reference_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['label'] = 'אירוע';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['operator'] = 'field_event_reference_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['identifier'] = 'field_event_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['reference_display'] = 'podcasts:entityreference_2';
  /* Filter criterion: Content: איכות רצועת שמע (field_podcast_quality) */
  $handler->display->display_options['filters']['field_podcast_quality_tid']['id'] = 'field_podcast_quality_tid';
  $handler->display->display_options['filters']['field_podcast_quality_tid']['table'] = 'field_data_field_podcast_quality';
  $handler->display->display_options['filters']['field_podcast_quality_tid']['field'] = 'field_podcast_quality_tid';
  $handler->display->display_options['filters']['field_podcast_quality_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_podcast_quality_tid']['expose']['operator_id'] = 'field_podcast_quality_tid_op';
  $handler->display->display_options['filters']['field_podcast_quality_tid']['expose']['label'] = 'איכות רצועת שמע';
  $handler->display->display_options['filters']['field_podcast_quality_tid']['expose']['operator'] = 'field_podcast_quality_tid_op';
  $handler->display->display_options['filters']['field_podcast_quality_tid']['expose']['identifier'] = 'field_podcast_quality_tid';
  $handler->display->display_options['filters']['field_podcast_quality_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_podcast_quality_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_podcast_quality_tid']['vocabulary'] = 'podcast_quality';
  /* Filter criterion: Content: נושא רצועת שמע (field_podcast_topic) */
  $handler->display->display_options['filters']['field_podcast_topic_tid']['id'] = 'field_podcast_topic_tid';
  $handler->display->display_options['filters']['field_podcast_topic_tid']['table'] = 'field_data_field_podcast_topic';
  $handler->display->display_options['filters']['field_podcast_topic_tid']['field'] = 'field_podcast_topic_tid';
  $handler->display->display_options['filters']['field_podcast_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_podcast_topic_tid']['expose']['operator_id'] = 'field_podcast_topic_tid_op';
  $handler->display->display_options['filters']['field_podcast_topic_tid']['expose']['label'] = 'נושא רצועת שמע';
  $handler->display->display_options['filters']['field_podcast_topic_tid']['expose']['operator'] = 'field_podcast_topic_tid_op';
  $handler->display->display_options['filters']['field_podcast_topic_tid']['expose']['identifier'] = 'field_podcast_topic_tid';
  $handler->display->display_options['filters']['field_podcast_topic_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_podcast_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_podcast_topic_tid']['vocabulary'] = 'podcast_topics';
  $handler->display->display_options['path'] = 'podcasts';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'רצועות שמע';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-library';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_teachers_reference' => 'field_teachers_reference',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['id'] = 'field_teachers_reference_target_id';
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['table'] = 'field_data_field_teachers_reference';
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['field'] = 'field_teachers_reference_target_id';
  $handler->display->display_options['relationships']['field_teachers_reference_target_id']['label'] = 'משתמש entity referenced from field_teachers_reference';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: מורים */
  $handler->display->display_options['fields']['field_teachers_reference']['id'] = 'field_teachers_reference';
  $handler->display->display_options['fields']['field_teachers_reference']['table'] = 'field_data_field_teachers_reference';
  $handler->display->display_options['fields']['field_teachers_reference']['field'] = 'field_teachers_reference';
  $handler->display->display_options['fields']['field_teachers_reference']['label'] = '';
  $handler->display->display_options['fields']['field_teachers_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teachers_reference']['settings'] = array(
    'link' => 0,
  );
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
    'podcast' => 'podcast',
  );

  /* Display: Entity Reference 2 */
  $handler = $view->new_display('entityreference', 'Entity Reference 2', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_event_reference' => 'field_event_reference',
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_reference_target_id']['id'] = 'field_event_reference_target_id';
  $handler->display->display_options['relationships']['field_event_reference_target_id']['table'] = 'field_data_field_event_reference';
  $handler->display->display_options['relationships']['field_event_reference_target_id']['field'] = 'field_event_reference_target_id';
  $handler->display->display_options['relationships']['field_event_reference_target_id']['label'] = 'תוכן entity referenced from field_event_reference';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: אירוע */
  $handler->display->display_options['fields']['field_event_reference']['id'] = 'field_event_reference';
  $handler->display->display_options['fields']['field_event_reference']['table'] = 'field_data_field_event_reference';
  $handler->display->display_options['fields']['field_event_reference']['field'] = 'field_event_reference';
  $handler->display->display_options['fields']['field_event_reference']['label'] = '';
  $handler->display->display_options['fields']['field_event_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_reference']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
    'event' => 'event',
  );

  /* Display: הזנה */
  $handler = $view->new_display('feed', 'הזנה', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: תקציר */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: איכות רצועת שמע */
  $handler->display->display_options['fields']['field_podcast_quality']['id'] = 'field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['table'] = 'field_data_field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['field'] = 'field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_quality']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'להמשך קריאה >';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'לעמוד התרומות >';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/397';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: כותב המאמר */
  $handler->display->display_options['fields']['field_article_author']['id'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['table'] = 'field_data_field_article_author';
  $handler->display->display_options['fields']['field_article_author']['field'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['label'] = '';
  $handler->display->display_options['fields']['field_article_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_author']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['path'] = 'podcasts/%/feed';

  /* Display: עמוד ניהול */
  $handler = $view->new_display('page', 'עמוד ניהול', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_description' => 'field_description',
    'field_podcast_quality' => 'field_podcast_quality',
    'view_node' => 'view_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_podcast_quality' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
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
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'תוכן';
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
    'action::node_save_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: איכות רצועת שמע */
  $handler->display->display_options['fields']['field_podcast_quality']['id'] = 'field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['table'] = 'field_data_field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['field'] = 'field_podcast_quality';
  $handler->display->display_options['fields']['field_podcast_quality']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_quality']['element_label_colon'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'מפורסם';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'מחיקה';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'עריכה';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'להמשך קריאה >';
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
    'podcast' => 'podcast',
  );
  /* Filter criterion: Content: מורים (field_teachers_reference) (reference filter) */
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['id'] = 'field_teachers_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['table'] = 'field_data_field_teachers_reference';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['field'] = 'field_teachers_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['operator_id'] = 'field_teachers_reference_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['label'] = 'סנן לפי מורה';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['operator'] = 'field_teachers_reference_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['identifier'] = 'field_teachers_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_teachers_reference_target_id_entityreference_filter']['reference_display'] = 'teachers_reference:entityreference_1';
  /* Filter criterion: Content: אירוע (field_event_reference) (reference filter) */
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['id'] = 'field_event_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['table'] = 'field_data_field_event_reference';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['field'] = 'field_event_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['operator_id'] = 'field_event_reference_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['label'] = 'סנן לפי אירוע';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['operator'] = 'field_event_reference_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['identifier'] = 'field_event_reference_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_event_reference_target_id_entityreference_filter']['reference_display'] = 'podcasts:entityreference_2';
  $handler->display->display_options['path'] = 'podcast-managment';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'ניהול רצועות שמע';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-menu-manager';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['podcasts'] = array(
    t('Master'),
    t('רצועות השמע'),
    t('more'),
    t('התאמה'),
    t('איתחול'),
    t('מיין לפי'),
    t('עולה'),
    t('יורד'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('User entity referenced from field_teachers_reference'),
    t('להמשך קריאה >'),
    t('לעמוד התרומות >'),
    t('מורים (field_teachers_reference)'),
    t('משתמש entity referenced from field_teachers_reference'),
    t('מורים'),
    t('אירוע'),
    t('איכות רצועת שמע'),
    t('נושא רצועת שמע'),
    t('Entity Reference'),
    t('Entity Reference 2'),
    t('תוכן entity referenced from field_event_reference'),
    t('הזנה'),
    t('עמוד ניהול'),
    t('מספר פריטים בעמוד'),
    t('- הכל -'),
    t('היסט'),
    t('« לעמוד הראשון'),
    t('‹ לעמוד הקודם'),
    t('לעמוד הבא ›'),
    t('לעמוד האחרון »'),
    t('תוכן'),
    t('- Choose an operation -'),
    t('שינוי ערכים'),
    t('מפורסם'),
    t('מחיקה'),
    t('עריכה'),
    t('סנן לפי מורה'),
    t('סנן לפי אירוע'),
  );
  $export['podcasts'] = $view;

  return $export;
}
