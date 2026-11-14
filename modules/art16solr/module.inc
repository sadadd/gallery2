<?php
/**
 * Gallery2 → Solr event bridge. No Drupal entities are created.
 * The asynchronous worker is intentionally separate from Gallery2 requests.
 */
class Art16SolrModule extends GalleryModule {
    function __construct() {
        global $gallery;
        $this->setId('art16solr');
        $this->setName($gallery->i18n('ART16 Solr bridge'));
        $this->setDescription($gallery->i18n('Queue album and photo changes for Solr'));
        $this->setVersion('1.0.0');
        $this->setGroup('export', $gallery->i18n('Export'));
        $this->setRequiredCoreApi(array(7, 53));
        $this->setRequiredModuleApi(array(3, 8));
    }

    function performFactoryRegistrations() {
        return GalleryCoreApi::registerFactoryImplementation(
            'GalleryEventListener',
            'Art16SolrEventListener',
            'Art16SolrEventListener',
            'modules/art16solr/classes/Art16SolrEventListener.class',
            'art16solr',
            array('GalleryEntity::save',
                  'GalleryEntity::delete',
                  'Gallery::ViewableTreeChange')
        );
    }
}
?>