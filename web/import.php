<!DOCTYPE html>
<html>
<head>
    <title>FullFillment import</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: linear-gradient(to right, #fce4ec, #f8bbd0);
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
            background: linear-gradient(to right, #ec407a, #f06292);
            color: white;
        }
        tr:nth-child(even) {
            background-color: #fce4ec;
        }
        tr:hover {
            background-color: #f8bbd0;
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
        select, input[type="text"], input[type="submit"] {
            padding: 10px;
            font-size: 16px;
            margin: 5px;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
        input[type="submit"] {
            background-color: #ec407a;
            color: white;
            cursor: pointer;
        }
        input[type="submit"]:hover {
            background-color: #f06292;
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
    </style>
    <script>
        function validateForm() {
            var tableSelect2 = document.getElementById("tableSelect2").value;
            var orderQuantity2 = document.getElementById("orderQuantity2").value;

            if (!tableSelect2 || !orderQuantity2) {
                alert("모든 항목을 선택하고 입력해주세요");
                return false;
            }
            if (orderQuantity2 > 5) {
                alert("주문갯수를 초과하였습니다");
                return false;
            }
            return true;
        }
    </script>
</head>
<body>
    <p>FullFillMent IMPORT  UI</p>

    <form method="post" action="" onsubmit="return validateForm()">
        <div>
            <label for="tableSelect2">입고상품:</label>
            <select id="tableSelect2" name="tableSelect2">
                <option value="">아이템을 선택하세요</option>
                <option value="eclipse">eclipse</option>
                <option value="box">box</option>
                <option value="clay">clay</option>
                <option value="soap">soap</option>
                <option value="cube">cube</option>
            </select>
            <label for="orderQuantity2">수량:</label>
            <input type="text" id="orderQuantity2" name="orderQuantity2" maxlength="1">
        </div>
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

        // 테이블 출력 함수 (입고테이블:supply)
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
                    if ($key != 'supply_id' && $key != 'supplier_id' && $key != 'supply_check') {
                        echo "<th>" . $key . "</th>";
                    }
                }
                echo "</tr>";
                // 테이블 내용 출력
                $result->data_seek(0); // 첫 번째 레코드로 다시 이동
                while ($row = $result->fetch_assoc()) {
                    echo "<tr>";
                    foreach ($row as $key => $value) {
                        if ($key != 'supply_id' && $key != 'supplier_id' && $key != 'supply_check') {
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

        // 선택한 테이블 출력 및 supply 테이블에 값 추가
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $selectedItem2 = $_POST['tableSelect2'];
            $orderQuantity2 = $_POST['orderQuantity2'];

            $supplySuccess = false;

            if ($selectedItem2 && $orderQuantity2 && $orderQuantity2 <= 5) {
                // supply 테이블에 값 추가
                $sqlInsertSupply2 = "INSERT INTO supply (item_id, supply_amount) VALUES ('$selectedItem2', '$orderQuantity2')";
                if ($conn->query($sqlInsertSupply2) === TRUE) {
                    $supplySuccess = true;
                } else {
                    echo "<script>alert('입고주문 중 오류가 발생하였습니다: " . $conn->error . "');</script>";
                }
            }

            if ($supplySuccess) {
                echo "<script>alert('주문이 성공적으로 추가되었습니다.');</script>";
            }

            printTable($conn, 'supply');
        }

        // MySQL 연결 종료
        $conn->close();
    ?>

</body>
</html>
