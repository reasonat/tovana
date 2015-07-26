<?php
/**
 * @file
 * recipe_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function recipe_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'recipes_context';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/640' => 'node/640',
        'node/641' => 'node/641',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-recipes_main_view-block' => array(
          'module' => 'views',
          'delta' => 'recipes_main_view-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['recipes_context'] = $context;

  return $export;
}
