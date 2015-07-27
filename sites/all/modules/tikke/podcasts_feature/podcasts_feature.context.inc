<?php
/**
 * @file
 * podcasts_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function podcasts_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'podcast_context';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/395' => 'node/395',
        'node/396' => 'node/396',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-podcast_page-block' => array(
          'module' => 'views',
          'delta' => 'podcast_page-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['podcast_context'] = $context;

  return $export;
}
