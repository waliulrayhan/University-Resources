<?php
include 'partials/header.php';

// fetch post from database if id is set
if (isset($_GET['id'])) {
    $id = filter_var($_GET['id'], FILTER_SANITIZE_NUMBER_INT);
    $query = "SELECT * FROM post WHERE id=$id";
    $result = mysqli_query($connection, $query);
    $post = mysqli_fetch_assoc($result);
} else {
    header('location: ' . ROOT_URL . 'user/user-index.php');
    die();
}
?>


<section class="singlepost">
    <div class="container singlepost__container">
        <div class="post__info">
            <?php
            // fetch category from categories table using category_id of post
            $category_id = $post['office_id'];
            $category_query = "SELECT * FROM adminaddoffice WHERE id=$category_id";
            $category_result = mysqli_query($connection, $category_query);
            $category = mysqli_fetch_assoc($category_result);
            ?>
            <h3><a href="<?= ROOT_URL ?>user/details-post.php?id=<?= $post['id'] ?>"><?= $post['type'] ?><?= $post['id'] ?></a></h3>
            <a href="<?= ROOT_URL ?>user/category-posts.php?id=<?= $post['office_id'] ?>" class="category__button"><?= $category['title'] ?></a>
            <h4 class="post__title">
                <!-- <a href="<?= ROOT_URL ?>post.php?id=<?= $post['id'] ?>"><?= $post['title'] ?></a> -->
                <?= date("d M Y - H:i", strtotime($post['date_time'])) ?>
            </h4>
            </br>
            <p class="post__body">
                <?= $post['body'] ?>
            </p>
            <div class="post__author">
                <div class="post__author-info">
                    <h5>Status: We have received your suggestion</h5>
                </div>
            </div>
        </div>
    </div>
</section>
<!-- ============= END OF SINGLE POST ============= -->


<!-- <?php
        include 'partials/footer.php';
        ?> -->