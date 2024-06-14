<!DOCTYPE html>
<html>
<head>
    <title>FullFillment export</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: linear-gradient(to right, #a8e063, #56ab2f); /* 초록색 그라데이션 */
            color: #333;
        }
        table {
            border-collapse: collapse;
            width: 80%;
            margin: 20px auto;
            margin-bottom: 40px;
            box-shadow: 0 0 20px rgba(0, 0, 0, 0.1);
            background: #fff;
        }
        th, td {
            border: 1px solid #dddddd;
            text-align: left;
            padding: 12px;
        }
        th {
            background: linear-gradient(to right, #4caf50, #8bc34a); /* 초록색 그라데이션 */
            color: white;
        }
        tr:nth-child(even) {
            background-color: #e8f5e9;
        }
        tr:hover {
            background-color: #c8e6c9;
        }
        p {
            text-align: center;
            font-size: 24px;
            margin-top: 20px;
            color: #333;
        }
        form {
            text-align: center;
            margin: 20px;
        }
        label {
            font-size: 18px;
            margin-right: 10px;
            color: #333;
        }
        select, input[type="text"], input[type="submit"], button {
            padding: 10px;
            font-size: 16px;
            margin: 5px;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
        input[type="submit"], button {
            background-color: #4caf50;
            color: white;
            cursor: pointer;
        }
        input[type="submit"]:hover, button:hover {
            background-color: #388e3c;
        }
        .message {
            text-align: center;
            font-size: 18px;
            color: green;
        }
        .error {
            text-align: center;
            font-size: 18px;
            color: red;
        }
        .order-item {
            margin-bottom: 10px;
        }
    </style>
    <script>
        let itemCount = 1;

        function addItem() {
            itemCount++;
            const container = document.getElementById('orderItems');
            const newItem = document.createElement('div');
            newItem.classList.add('order-item');
            newItem.innerHTML = `
                <label for="tableSelect${itemCount}">주문상품 ${itemCount}:</label>
                <select id="tableSelect${itemCount}" name="tableSelect${itemCount}">
                    <option value="">아이템 선택</option>
                    <option value="eclipse">eclipse</option>
                    <option value="box">box</option>
                    <option value="clay">clay</option>
                    <option value="soap">soap</option>
                    <option value="cube">cube</option>
                </select>
                <label for="orderQuantity${itemCount}">수량:</label>
                <input type="text" id="orderQuantity${itemCount}" name="orderQuantity${itemCount}" maxlength="1">
                <label for="orderAddress${itemCount}">주소:</label>
                <input type="text" id="orderAddress${itemCount}" name="orderAddress${itemCount}">
            `;
            container.appendChild(newItem);
        }

        function validateForm() {
            for (let i = 1; i <= itemCount; i++) {
                let tableSelect = document.getElementById("tableSelect" + i).value;
                let orderQuantity = document.getElementById("orderQuantity" + i).value;
                let orderAddress = document.getElementById("orderAddress" + i).value;

                if (!tableSelect || !orderQuantity || !orderAddress) {
                    alert("모든 항목을 선택하고 입력해주세요");
                    return false;
                }
                if (orderQuantity > 5) {
                    alert("주문갯수를 초과하였습니다");
                    return false;
                }
            }
            return true;
        }
    </script>
</head>
<body>
    <p>FullFillMent EXPORT UI</p>

    <form method="post" action="" onsubmit="return validateForm()">
        <div id="orderItems">
            <div class="order-item">
                <label for="tableSelect1">주문상품 1:</label>
                <select id="tableSelect1" name="tableSelect1">
                    <option value="">아이템 선택</option>
                    <option value="eclipse">eclipse</option>
                    <option value="box">box</option>
                    <option value="clay">clay</option>
                    <option value="soap">soap</option>
                    <option value="cube">cube</option>
                </select>
                <label for="orderQuantity1">수량:</label>
                <input type="text" id="orderQuantity1" name="orderQuantity1" maxlength="1">
                <label for="orderAddress1">주소:</label>
                <input type="text" id="orderAddress1" name="orderAddress1">
            </div>
        </div>
        <button type="button" onclick="addItem()">+</button>
        <input type="submit" value="주문넣기">
    </form>

    <?php
        $servername = "localhost";
        $username = "root";
        $password = "1234";
        $dbname = "kairos";

        // MySQL 연결
        $conn = new mysqli($servername, $username, $password, $dbname);

        // 연결 확인
        if ($conn->connect_error) {
            die("연결 실패: " . $conn->connect_error);
        }

        // 테이블 출력 함수 (출고테이블: order_item)
        function printTable($conn, $tableName) {
            $sql = "SELECT * FROM $tableName";
            $result = $conn->query($sql);

            echo "<p>$tableName 테이블</p>";

            if ($result->num_rows > 0) {
                echo "<table>";
                // 테이블 헤더 출력
                echo "<tr>";
                $firstRow = $result->fetch_assoc();
                foreach ($firstRow as $key => $value) {
                    if ($key != 'order_item_id') {
                        echo "<th>" . $key . "</th>";
                    }
                }
                echo "</tr>";
                // 테이블 내용 출력
                $result->data_seek(0); // 첫 번째 레코드로 다시 이동
                while ($row = $result->fetch_assoc()) {
                    echo "<tr>";
                    foreach ($row as $key => $value) {
                        if ($key != 'order_item_id') {
                            echo "<td>" . $value . "</td>";
                        }
                    }
                    echo "</tr>";
                }
                echo "</table>";
            } else {
                echo "<p>테이블 내용을 찾을 수 없습니다.</p>";
            }
        }

        // 선택한 테이블 출력 및 order_item 테이블에 값 추가
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $orderItemSuccess = false;

            for ($i = 1; isset($_POST['tableSelect' . $i]); $i++) {
                $selectedItem = $_POST['tableSelect' . $i];
                $orderQuantity = $_POST['orderQuantity' . $i];
                $orderAddress = $_POST['orderAddress' . $i];

                if ($selectedItem && $orderQuantity && $orderQuantity <= 5 && $orderAddress) {
                    // order_item 테이블에 값 추가
                    $sqlInsertOrderItem = "INSERT INTO order_item (order_item, order_item_amount, address) VALUES ('$selectedItem', '$orderQuantity', '$orderAddress')";
                    if ($conn->query($sqlInsertOrderItem) === TRUE) {
                        $orderItemSuccess = true;
                    } else {
                        echo "<script>alert('출고주문 중 오류가 발생하였습니다: " . $conn->error . "');</script>";
                    }
                }
            }

            if ($orderItemSuccess) {
                echo "<script>alert('주문이 성공적으로 추가되었습니다.');</script>";
            }

            printTable($conn, 'order_item');
        }

        // MySQL 연결 종료
        $conn->close();
    ?>

</body>
</html>
