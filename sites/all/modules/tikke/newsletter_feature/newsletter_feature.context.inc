<?php
/**
 * @file
 * newsletter_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function newsletter_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'newsletter_context';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/538' => 'node/538',
        'node/539' => 'node/539',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-newsletters_view-block' => array(
          'module' => 'views',
          'delta' => 'newsletters_view-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-newsletters_view-block_1' => array(
          'module' => 'views',
          'delta' => 'newsletters_view-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['newsletter_context'] = $context;

  return $export;
}
