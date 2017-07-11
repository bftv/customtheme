<?php
/**
 * @file
 * Helper functions for the SiteFarm One theme.
 */

/**
 * Fetch the category brand color name for a given node
 *
 * @param $entity
 * @return string - color name or bool FALSE if not set
 */
function sitefarm_one_get_category_brand($entity) {
  $article_category_field = theme_get_setting('article_category_field');
  $event_category_field = theme_get_setting('event_category_field');
  $photo_gallery_category_field = theme_get_setting('photo_gallery_category_field');
  $branding_field = theme_get_setting('branding_field');
  $brand_color_field = theme_get_setting('brand_color_field');

  // Node
  if ($entity->getEntityTypeId() == 'node') {
    // Articles
    if ($entity->$article_category_field && !$entity->$article_category_field->isEmpty()) {
      // Grab the first category term
      return $entity->$article_category_field->entity->$brand_color_field->value;
    }
    // News Articles
    if ($entity->$news_article_category_field && !$entity->$news_article_category_field->isEmpty()) {
      // Grab the first category term
      return $entity->$news_article_category_field->entity->$brand_color_field->value;
    }
    // Events
    else if ($entity->$event_category_field && !$entity->$event_category_field->isEmpty()) {
      // Grab the first category term
      return $entity->$event_category_field->entity->$brand_color_field->value;
    }
    // Photo Galleries
    else if ($entity->$photo_gallery_category_field && !$entity->$photo_gallery_category_field->isEmpty()) {
      // Grab the first category term
      return $entity->$photo_gallery_category_field->entity->$brand_color_field->value;
    }
    // Nodes with the Branding Taxonomy
    else if ($entity->$branding_field && !$entity->$branding_field->isEmpty()) {
      // Grab the first category term
      return $entity->$branding_field->entity->$brand_color_field->value;
    }
    else {
      return FALSE;
    }
  }

  // Taxonomy
  if ($entity->getEntityTypeId() == 'taxonomy_term'
    && $entity->$brand_color_field
    && !$entity->$brand_color_field->isEmpty()
  ) {
    return $entity->$brand_color_field->value;
  }
  else {
    return FALSE;
  }

}
