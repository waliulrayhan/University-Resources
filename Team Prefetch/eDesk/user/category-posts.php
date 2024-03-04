<?php
include 'partials/header.php';

// fetch posts if id is set
if (isset($_GET['id'])) {
    $id = filter_var($_GET['id'], FILTER_SANITIZE_NUMBER_INT);
    $query = "SELECT * FROM post WHERE office_id=$id ORDER BY date_time DESC";
    $posts = mysqli_query($connection, $query);
} else {
    header('location: ' . ROOT_URL . 'user/user-index.php');
    die();
}
?>


<header class="category__title">
    <h2>
        <?php
        // fetch category from adminaddoffice table using category_id of post
        $category_id = $id;
        $category_query = "SELECT * FROM adminaddoffice WHERE id=$id";
        $category_result = mysqli_query($connection, $category_query);
        $category = mysqli_fetch_assoc($category_result);
        echo $category['title'];
        ?>
    </h2>
</header>
<!-- ============= END OF CATEGORY TITLE ============= -->


<?php if (mysqli_num_rows($posts) > 0) : ?>
    <section class="posts">
        <div class="container posts__container">
            <?php while ($post = mysqli_fetch_assoc($posts)) : ?>
                <article class="post">
                    <?php if ($post['user_id']) : ?>
                        <div class="post__info">
                            <!-- <h3 class="post__title">
                            <a href="<?= ROOT_URL ?>post.php?id=<?= $post['id'] ?>"><?= $post['title'] ?></a>
                        </h3> -->
                            <h3><?= $post['type'] ?><?= $post['id'] ?></h3>
                            <b><?= date("d M Y - H:i", strtotime($post['date_time'])) ?></b>
                            </br>
                            </br>
                            <p class="post__body">
                                <?= substr($post['body'], 0, 150) ?>...
                            </p>
                            <div class="post__author">
                                <div class="post__author-info">
                                    <h5>Status: We have received your suggestion</h5>
                                </div>
                            </div>
                        </div>
                    <?php endif ?>
                </article>
            <?php endwhile ?>
        </div>
    </section>
<?php else : ?>
    <div class="alert__message error lg">
        <p>No post found for this category</p>
    </div>
<?php endif ?>
<!-- ============= END OF POSTS ============= -->


<!-- <?php
        include 'partials/footer.php';
        ?> -->