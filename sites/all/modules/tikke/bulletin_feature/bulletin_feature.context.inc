<?php
/**
 * @file
 * bulletin_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bulletin_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'communal_bulletin_board';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/361' => 'node/361',
        'node/360' => 'node/360',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-communal_bulletin_board-block' => array(
          'module' => 'views',
          'delta' => 'communal_bulletin_board-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['communal_bulletin_board'] = $context;

  return $export;
}
